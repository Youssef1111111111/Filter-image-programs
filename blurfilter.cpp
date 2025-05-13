#include <iostream>
#include "Image_Class.h"

using namespace std;

void imageBlur(Image &image) {
    int width = image.width;
    int height = image.height;

    // Create a temporary image to store the blurred result
    Image blurredImage(width, height);

    // Apply box blur
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Initialize sum for each channel
            int sumR = 0, sumG = 0, sumB = 0;

            // Loop through the surrounding pixels (3x3 matrix)
            for (int j = -10; j <= 10; ++j) {
                for (int i = -10; i <= 10; ++i) {
                    // Calculate the coordinates of the surrounding pixel
                    int neighborX = x + i;
                    int neighborY = y + j;

                    // Check if the surrounding pixel is within the image boundaries
                    if (neighborX >= 0 && neighborX < width && neighborY >= 0 && neighborY < height) {
                        // Accumulate the color values
                        sumR += image(neighborX, neighborY, 0);
                        sumG += image(neighborX, neighborY, 1);
                        sumB += image(neighborX, neighborY, 2);
                    }
                }
            }

            // Calculate the average color values
            int avgR = sumR / 441;
            int avgG = sumG / 441;
            int avgB = sumB / 441;

            // Set the new pixel value in the blurred image
            blurredImage(x, y, 0) = avgR;
            blurredImage(x, y, 1) = avgG;
            blurredImage(x, y, 2) = avgB;
        }
    }

    // Copy the blurred image back to the original image
    for (int i = 0; i < width * height * 3; ++i) {
        image.imageData[i] = blurredImage.imageData[i];
    }
}

int main() {
    string filename;
    cout << "Please enter the colored image name: ";
    cin >> filename;

    Image image(filename);
    imageBlur(image);

    
    cout << "Enter filename to save the blurred image: ";
    cin >> filename;
    image.saveImage(filename);

    return 0;
}
