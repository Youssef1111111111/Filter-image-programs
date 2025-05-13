#include <iostream>
#include "Image_Class.h"

using namespace std;

void createFrame() {
    string filename;
    cout << "Please enter the image name to make a frame for: ";
    cin >> filename;

    Image image(filename);
    char frameType;
    int frameColor, frameRed = 0, frameGreen = 0, frameBlue = 0;

    cout << "1) Simple frame\n";
    cout << "2) Fancy frame\n";
    cout << "Please select the type of frame: ";
    cin >> frameType;

    cout << "1) blue\n";
    cout << "2) Red\n";
    cout << "3) green\n";
    cout << "Please select the color for the frame: ";
    cin >> frameColor;


    frameBlue = (frameColor == 1) ? 225 : 0;
    frameRed = (frameColor == 2) ? 225 : 0;
    frameGreen = (frameColor == 3) ? 225 : 0;
    

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            bool isFrame = (i <= image.width / 50) || (j <= image.height / 40) || (i >= image.width - image.width / 50) || (j >= image.height - image.height / 40);
            bool isInnerFrame = (i <= image.width / 80) || (j <= image.height / 80) || (i >= image.width - image.width / 80) || (j >= image.height - image.height / 80);
            bool isFancyFrame = (i <= image.width / 30 || i >= image.width - image.width / 30) && (j <= image.height / 20 || j >= image.height - image.height / 20);

            if (frameType == '1') {
                if (isFrame) {
                    image(i, j, 0) = frameRed;
                    image(i, j, 1) = frameGreen;
                    image(i, j, 2) = frameBlue;
                }
                if (isInnerFrame) {
                    image(i, j, 0) = 225;
                    image(i, j, 1) = 225;
                    image(i, j, 2) = 225;
                }
            } else if (frameType == '2') {
                if (isFrame) {
                    image(i, j, 0) = frameRed;
                    image(i, j, 1) = frameGreen;
                    image(i, j, 2) = frameBlue;
                }
                if (isInnerFrame) {
                    image(i, j, 0) = 30;
                    image(i, j, 1) = 30;
                    image(i, j, 2) = 30;
                }
                if (isFancyFrame) {
                    image(i, j, 0) = 50;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 225;
                }
            }
        }
    }

    cout << "Please enter the image name to store the new image and specify extension (.jpg, .bmp, .png, .tga): ";
    cin >> filename;
    image.saveImage(filename);
}

int main() {
    createFrame();
    return 0;
}
