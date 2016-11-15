#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Pixel {
    int red, green, blue;
    Pixel();
    Pixel(int new_red, int new_green, int new_blue);
};

class Picture
{
private:
    vector<vector<Pixel> > picture_data;
    int width = 0, height = 0, max_saturation = 0;

public:
    bool read_image(ifstream& file_data);
    bool write_image(ofstream& output_file);

    void flip_horizontal();
    void flip_vertical();
    void invert_colors();
};

int main(int argc, char** argv)
{
    // argv( in, out, mod? )

    Picture original_pic;

    // Test arguments for validity
    if((argc != 3) && (argc != 4)) {
        cout << "Usage: inputfile outputfile [XYI]" << endl;
        return 1;
    }
    if(argc == 4) {
        string operation = argv[3];
        if(operation != "X" && operation != "Y" && operation != "I") {
            cout << "Error: " << argv[3] << " is an invalid command. Use either X, Y, or I." << endl;
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

    bool read_file_success = original_pic.read_image(input_file);

    if(!read_file_success) {
        cout << "Error: unable to read PPM file '" << input_filename << "'" << endl;
        return 1;
    }

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
    string file_header, temp;
    istringstream dimensions, saturation, ss_pixel;
    Pixel temp_pixel;

    getline(file_data, file_header);

    if(file_header != "P3") {
        // This is not the right kind of file...
        return false;
    }

    // For the initial picture setup:

    dimensions.clear();
    saturation.clear();

    getline(file_data, temp);
    dimensions.str(temp);
    dimensions >> width >> height;

    getline(file_data, temp);
    saturation.str(temp);
    saturation >> max_saturation;

    cout << "Width: " << width << " Height: " << height << " Saturation: " << max_saturation << endl;

    if(width <= 0 || height <= 0 || max_saturation <= 0) {
        // Well that isn't a good picture...
        return false;
    }

    int current_x = 0, current_y = 0;

    for(current_y = 0; current_y < height; current_y++) {
        vector<Pixel> new_line;
        picture_data.push_back(new_line);
        for(current_x = 0; current_x < width; current_x++) {
            temp_pixel.red = temp_pixel.green = temp_pixel.blue = -1;
            ss_pixel.clear();
            getline(file_data, temp);
            ss_pixel.str(temp);
            ss_pixel >> temp_pixel.red >> temp_pixel.green >> temp_pixel.blue;
            if (temp_pixel.red < 0 || temp_pixel.green < 0 || temp_pixel.blue < 0) {
                // Image does not contain enough data...
                return false;
            }
            picture_data[current_y].push_back(temp_pixel);
        }
    }

    //cout << "read all that picture data last pixel blue: " << temp_pixel.blue << endl;

    return true;
}

bool Picture::write_image(ofstream &output_file) {

    output_file << "P3\n";
    output_file << width << " " << height << "\n";
    output_file << max_saturation << "\n";

    for(current_y = 0; current_y < height; current_y++) {
        for(current_x = 0; current_x < width; current_x++) {

        }
    }

    return true;
}
