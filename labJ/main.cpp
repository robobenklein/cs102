#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct Pixel {
    int red, green, blue;

    Pixel ();
    Pixel (int new_red, int new_green, int new_blue);
};

class Picture {
private:
    vector<vector<Pixel>> picture_data;

public:
    bool read_image (ifstream file_data);
    bool write_image (ofstream output_file);

    void flip_horizontal ();
    void flip_vertical ();
    void invert_colors ();
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

// Pixel Structure definitions
Pixel::Pixel() {
    red = 0;
    green = 0;
    blue = 0;
}
Pixel::Pixel(int new_red, int new_green, int new_blue) {
    red = new_red;
    green = new_green;
    blue = new_blue;
}

// Picture Class definitions
