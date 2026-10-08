#include <iostream>
#include "Image_class.h"
using namespace std;

Image Blur_Filter(Image img){
    int radius, bluredPixels;
    cout << "Enter the blur radius: ";
    cin >> radius;
    bluredPixels = ((2 * radius) + 1) * ((2 * radius) + 1);

    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            int redSum = 0, greenSum = 0, blueSum = 0;
            for (int iLocation = -radius; iLocation <= radius; iLocation++) {
                for (int jLocation = -radius; jLocation <= radius; jLocation++) {
                    if (i + iLocation >= 0 and i + iLocation < img.width and 
                        j + jLocation >= 0 and j + jLocation < img.height) {
                        redSum += img.getPixel(i + iLocation, j + jLocation, 0);
                        greenSum += img.getPixel(i + iLocation, j + jLocation, 1);
                        blueSum += img.getPixel(i + iLocation, j + jLocation, 2);
                    }
                }
            }
            img.setPixel(i, j, 0, redSum / bluredPixels);
            img.setPixel(i, j, 1, greenSum / bluredPixels);
            img.setPixel(i, j, 2, blueSum / bluredPixels);
        }
    }
    return img;
}

int main(){
    Image img("mario.bmp");
    Image bluredImg = Blur_Filter(img);
    bluredImg.saveImage("blured mario.jpg");
}
