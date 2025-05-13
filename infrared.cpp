#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename;
    cout << "Please enter the colored image name to apply the infrared filter: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Calculate the brightness of the pixel
            unsigned int brightness = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;

            // Determine whether the pixel is bright or dark
            if (brightness > 128) {
                // Bright pixels become a mix of shiny white and slightly decreased red
                unsigned int redIntensity = brightness + 99; // Adjust the boost factor as needed
                unsigned int whiteIntensity = 255 - brightness;
                // Ensure redIntensity doesn't exceed 255
                if (redIntensity > 255) redIntensity = 255;
                // Set the pixel color to shiny white-red
                image(i, j, 0) = redIntensity; // Red
                image(i, j, 1) = whiteIntensity; // Green (to mix with red)
                image(i, j, 2) = whiteIntensity; // Blue (to mix with red)
            } else {
                // Dark pixels become closer to white
                // Increase the intensity of all color channels
                unsigned int intensity = 255 - brightness;
                // Adjust the intensity to make dark parts closer to white
                intensity = 255 - intensity; // Make dark pixels closest to white
                image(i, j, 0) = 255 - intensity; // Red
                image(i, j, 1) = 255 - intensity; // Green
                image(i, j, 2) = 255 - intensity; // Blue
            }
        }
    }
    
    cout << "Please enter the image name to store the new infrared-like image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";

    cin >> filename;
    image.saveImage(filename);

    return 0;
}
