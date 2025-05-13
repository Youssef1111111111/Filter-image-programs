#include <iostream>
using namespace std;
#include "Image_Class.h"

int main() {
    string filename;
    cout << "Please enter the name of the coloured image : ";
    cin >> filename;
    
    Image image(filename);
    cout << "please enter the angle you want to rotate the image from: " ;
    string angle  ;
    cin>> angle ;
    while (stoi (angle) != 90  and stoi(angle) != 180 and stoi(angle) != 270 )  {
        cout << " invalid input , please try again to enter the angle (90 , 180 , 270  ): ";
        cin>> angle;
    }

    Image Rotate(image.height,image.width);

    if (stoi(angle) == 90){
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
            Rotate(j,image.width -i-1,0) = image (i,j,0) ;
            Rotate(j,image.width -i-1,1) = image (i,j,1) ;
            Rotate(j,image.width -i-1,2) = image (i,j,2) ;

            }
        }
    }
    if (stoi(angle) ==180){
         for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
            Rotate(image.height -j-1,image.width -i-1,0) = image (i,j,0) ;
            Rotate(image.height -j-1,image.width -i-1,1) = image (i,j,1) ;
            Rotate(image.height -j-1,image.width -i-1,2) = image (i,j,2) ;

            }
        }

    }
    if (stoi(angle) ==270){
         for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
            Rotate(image.height -j-1,i,0) = image (i,j,0) ;
            Rotate(image.height -j-1,i,1) = image (i,j,1) ;
            Rotate(image.height -j-1,i,2) = image (i,j,2) ;

            }
        }
    }
        
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    Rotate.saveImage(filename);

    return 0;
}