#include <iostream>
#include "Image_class.h"
using namespace std;

Image Infrared_Filter(Image img) {
    for(int i = 0; i < img.width; i++) {
        for(int j = 0; j < img.height; j++) {
            //Taking average 
            int avg = (img.getPixel(i, j, 0) + img.getPixel(i, j, 1) + img.getPixel(i, j, 2)) / 3;
            //when the average close to 255(Bright) so the pixel become red(255,0,0) 
            //and when the average close to 0(Dark) so the pixel become white(255,255,255)
            img.setPixel(i, j, 0, 255);
            img.setPixel(i, j, 1, 255-avg);
            img.setPixel(i, j, 2, 255-avg);
        }
    }
    return img;
}
int main() {
    Image img("samurai.jpg");
    Image infraredImg = Infrared_Filter(img);
    infraredImg.saveImage("infrared samurai.jpg");
} 