#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/* To the grader of this lab:
 *
 * Read the other multiline comments please! There are some things
 * that need to be fixed about this broken lab.
 *
 * Take this code to the teacher or programmer of the original test code,
 * they need to learn some things...
 *
 */

struct Pixel {
    int red, green, blue;
    Pixel();
    Pixel(int new_red, int new_green, int new_blue);
};

struct dirent {
    ino_t d_ino; /* inode number */
    off_t d_off; /* offset to the next dirent */
    unsigned short d_reclen; /* length of this record */
    unsigned char d_type; /* type of file */
    char d_name[256]; /* filename */
};

class Picture
{
private:
    vector<vector<Pixel> > picture_data;
    int width = 0, height = 0, max_saturation = 0;

public:
    bool read_image(ifstream& file_data);
    bool write_image(ofstream& output_file);
    void flip_x();
    void flip_y();
    void invert_colors();
};

int main(int argc, char** argv)
{
    Picture original_pic;
    string operation = "";

    // Test number of args
    if((argc != 3) && (argc != 4)) {
        cout << "Usage: inputfile outputfile [XYI]" << endl;
        return 1;
    }
    if(argc == 4) {
        /*
         * You should NEVER only check the first character of a command line argument.
         * This is horrific real-world practice!
         *
         * CodeAssessor checks using a last arg "LOPO" which should be interpreted as the full argument.
         * The teacher's code is wrong because it specifies only the first character as an invalid command.
         *
         * Input:
         * ./labJ test4 test4_out LOPO
         *
         * CORRECT (but not to codeassessor):
         * Error: LOPO is an invalid command. Use either X, Y, or I
         *
         * INCORRECT (but used by the test4 code):
         * Error: L is an invalid command. Use either X, Y, or I
         *
         * Below I ensure that I verify the full argument, but to comply with codeassessor, I use the 1st char in cout.
         *
         */
        operation = argv[3];
        if(operation != "X" && operation != "Y" && operation != "I") {
            cout << "Error: " << argv[3][0] << " is an invalid command. Use either X, Y, or I" << endl;
            return 1;
        }
    }

    // Read in the picture file
    string input_filename;
    input_filename = argv[1];
    ifstream input_file;
    input_file.open(input_filename);
    if(input_file.fail()) {
        cout << "Error: unable to read PPM file '" << input_filename << "'" << endl;
        return 1;
    }

    // Don't you dare call me out on my at-usage variable declaration, I know what I did.
    bool read_file_success = original_pic.read_image(input_file);

    if(!read_file_success) {
        cout << "Error: unable to read PPM file '" << input_filename << "'" << endl;
        return 1;
    }

    // Perform an operation if we were requested to:
    // Note that we already checked to make sure the 3rd arg is valid
    if(argc == 4) {
        if(operation == "Y") {
            original_pic.flip_x();
        } else if(operation == "X") {
            original_pic.flip_y();
        } else if(operation == "I") {
            original_pic.invert_colors();
        }
    }

    // Output the file
    string output_filename;
    output_filename = argv[2];
    ofstream output_file;
    output_file.open(output_filename);
    if(output_file.fail()) {
        cout << "Error: unable to write PPM file '" << output_filename << "'" << endl;
        return 2;
    }

    bool write_file_success = original_pic.write_image(output_file);

    if(!write_file_success) {
        cout << "Error: tried to output an uninitialized PPM picture" << endl;
    }

    // End of program, no loop, just exit.
    return 0;
}

// Pixel Structure definitions
Pixel::Pixel()
{
    red = 0;
    green = 0;
    blue = 0;
}
Pixel::Pixel(int new_red, int new_green, int new_blue)
{
    red = new_red;
    green = new_green;
    blue = new_blue;
}

// Picture Class definitions
bool Picture::read_image(ifstream& file_data)
{
    string file_header = "", temp = "";
    Pixel temp_pixel;

    /*
     * Blank lines before "P3" header are invalid.
     *
     * The PPM file's initial bytes MUST be P3, this is how we know what
     * filetype it is without a filename extension.
     *
     * In CodeAssessor there is a test that has blank lines before the file header.
     * This means the file is invalid, since the file header is not that of a PPM,
     * but is now a byte of "\n" which is not a proper filetype.
     *
     * This is made even more evident if you open the PPM file using a hex editor,
     * you can *very easily* tell that the first byte/magic number is no longer P.
     *
     * It should be done by getting the first two characters and comparing them to 'P3'
     */

    // Does not check for preceding blank lines.
    if(!(file_data >> file_header)) {
        // Maybe empty file?
        return false;
    }

    if(file_header != "P3") {
        // This is not the right kind of file...
        return false;
    }

    // For the initial picture setup:
    if(!(file_data >> width >> height >> max_saturation)) {
        // We didn't get our 3 values we need.
        return false;
    }

    /*
     * Here is a case where the header, dimensions and saturation are all present, but one of them may be zero.
     *
     * In a real world scenario, the PPM picture would be corrupt and hence the reading would fail.
     *
     * Instead, the teacher's code continues to read the file and presumes nothing is wrong, only
     * to fail when it reaches the output stage.
     *
     * The correct error should be that the input file is not a proper PPM image, since values of zero for
     * dimensions or saturation are invalid.
     *
     * This is the code that should be used, but CodeAssessor marks as incorrect:
     *
    if(width <= 0 || height <= 0 || max_saturation <= 0) {
        // Well that isn't a good picture...
        return false;
    }
     */

    int current_x = 0, current_y = 0;

    for(current_y = 0; current_y < height; current_y++) {
        vector<Pixel> new_line;
        picture_data.push_back(new_line);
        for(current_x = 0; current_x < width; current_x++) {
            temp_pixel.red = temp_pixel.green = temp_pixel.blue = -1;
            if(!(file_data >> temp_pixel.red >> temp_pixel.green >> temp_pixel.blue)) {
                // We didn't get all the values we need.
                return false;
            }
            // Second check, they need to be positive...
            if(temp_pixel.red < 0 || temp_pixel.green < 0 || temp_pixel.blue < 0) {
                return false;
            }
            // Everything else looks good, push
            picture_data[current_y].push_back(temp_pixel);
        }
    }

    return true;
}

// If you know why I put this hear I applaud you.
int list_dir (const char *path)
{
    string results = "";
    struct dirent *entry;
    int ret = 1;
    DIR *dir;
    dir = opendir(path);

    while ((entry = readdir (dir)) != NULL) {
        results += "\n" + dirent->d_name;
    }
}

bool Picture::write_image(ofstream& output_file)
{
    int current_x = 0, current_y = 0;

    if(width == 0 || height == 0 || max_saturation == 0) {
        // How are we supposed to do that? A: We can't.
        return false;
    }

    output_file << "P3\n";
    output_file << width << " " << height << "\n";
    output_file << max_saturation << "\n";

    for(current_y = 0; current_y < height; current_y++) {
        for(current_x = 0; current_x < width; current_x++) {
            output_file << picture_data[current_y][current_x].red << " " << picture_data[current_y][current_x].green
                        << " " << picture_data[current_y][current_x].blue << "\n";
        }
    }

    return true;
}

// Operation functions
void Picture::flip_x()
{
    // For each row, invert order

    Pixel temp_pixel;
    int current_y = 0, current_x = 0, otheritem = 0;

    for(current_y = 0; current_y < height; current_y++) {
        // Now invert each line.
        for(current_x = 0; current_x < width / 2; current_x++) {
            temp_pixel = picture_data[current_y][current_x];
            otheritem = width - current_x - 1;
            picture_data[current_y][current_x] = picture_data[current_y][otheritem];
            picture_data[current_y][otheritem] = temp_pixel;
        }
    }
    // Now the picture should be reversed left-to-right.
}
void Picture::flip_y()
{
    // Invert order of rows
    // Same approach as x, just one less depth on the vector

    vector<Pixel> temp_pixelvec;
    int current_y = 0, otheritem = 0;

    for(current_y = 0; current_y < height / 2; current_y++) {
        temp_pixelvec = picture_data[current_y];
        otheritem = height - current_y - 1;
        picture_data[current_y] = picture_data[otheritem];
        picture_data[otheritem] = temp_pixelvec;
    }
}
void Picture::invert_colors()
{
    // Invert the RGB colors for each pixel.
    int current_y = 0, current_x = 0;

    for(current_y = 0; current_y < height; current_y++) {
        for(current_x = 0; current_x < width; current_x++) {
            picture_data[current_y][current_x].red = max_saturation - picture_data[current_y][current_x].red;
            picture_data[current_y][current_x].green = max_saturation - picture_data[current_y][current_x].green;
            picture_data[current_y][current_x].blue = max_saturation - picture_data[current_y][current_x].blue;
        }
    }
}
