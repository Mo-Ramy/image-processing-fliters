#include <iostream>
#include "Image_Class.h"
using namespace std;

Image Resize_Filter(Image img){

    int width,height;
    cout<<"Enter the dimensions of the new image "<<endl;
    cout<<"Width: ";
    cin>>width;
    cout<<"Height: ";
    cin>>height;
    Image img2(width,height);

    //transferring the pixels of the original image to the new image with the new size
    for (int i=0;i<img2.width;i++){
        for (int j=0;j<img2.height;j++){

            int ratioWidth=i*img.width/width;
            int ratioHeight=j*img.height/height;
            img2.setPixel(i,j,0,img.getPixel(ratioWidth,ratioHeight,0));
            img2.setPixel(i,j,1,img.getPixel(ratioWidth,ratioHeight,1));
            img2.setPixel(i,j,2,img.getPixel(ratioWidth,ratioHeight,2));
        }
    }
    return img2;

}
int main() {

    Image img("mario.bmp");
    Image resizedImage = Resize_Filter(img);
    resizedImage.saveImage("resized mario.jpg");
    return 0;
}