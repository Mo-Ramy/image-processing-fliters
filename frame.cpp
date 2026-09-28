#include <iostream>
#include "Image_Class.h"
using namespace std;

Image Frame_Filter(Image img){

    int frameSize;
    cout << "Enter frame size: ";
    cin >> frameSize;
    int r,g,b;
    cout << "Enter frame color "<<endl;
    cout << "Red: ";
    cin >>r;
    cout << "Green: ";
    cin >> g;
    cout << "Blue: ";
    cin >> b;

    Image img2(img.width+(2*frameSize), img.height+(2*frameSize));

    //puting the original image in the center of the new image that is slightly bigger than it
    for (int i=0;i<img.width;i++){
        for (int j=0;j<img.height;j++){

            img2.setPixel(i+frameSize,j+frameSize,0,img.getPixel(i,j,0));
            img2.setPixel(i+frameSize,j+frameSize,1,img.getPixel(i,j,1));
            img2.setPixel(i+frameSize,j+frameSize,2,img.getPixel(i,j,2));
        }
    }

    for (int i=0;i<img2.width;i++){
        for (int j=0;j<img2.height;j++){

                //putting the frame around the image
                if(i<=frameSize or j<=frameSize or i>=img2.width-frameSize-1 or j>=img2.height-frameSize-1){
                    
                    img2.setPixel(i,j,0,r);
                    img2.setPixel(i,j,1,g);
                    img2.setPixel(i,j,2,b);
                }
                //make the frame fancier
                if(i>=frameSize-1 and i<=frameSize or j>=frameSize-1 and j<=frameSize
                     or i>=img2.width-(frameSize+1) and i<=img2.width-frameSize or 
                        j>=img2.height-(frameSize+1) and j<=img2.height-frameSize)
                {
                    img2.setPixel(i,j,0,0);
                    img2.setPixel(i,j,1,0);
                    img2.setPixel(i,j,2,0);
                }
        }
    }
    return img2;
}
int main() {

    Image img("mario.bmp");
    Image framedimage = Frame_Filter(img);
    framedimage.saveImage("framed mario.jpg");
    
    return 0;
}