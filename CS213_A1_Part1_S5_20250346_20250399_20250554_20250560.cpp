//1-Name : Abdelrahman Ahmed Elsayed    ID : 20250346     Filters : 1-Grayscale Conversion , 5-Flip Image       Section : S5
//2-Name : Ali Sayed Khamees            ID : 20250399     Filters : 2-Black & White , 6-Rotate Image            Section : S5
//3-Name : Mohamed Hossam Abdelsamad    ID : 20250554     Filters : 3-Invert Image , 7-Darken & lighten Image   Section : S5
//4-Name : Mohamed Ramy Mohamed         ID : 20250560     Filters : 4-Adding Frame , 8-Resizing Image           Section : S5



#include <iostream>
#include "Image_Class.h"
using namespace std;


Image GrayScale_Filter(Image image);//Abdelrahman Ahmed Elsayed
Image Black_and_White_filter(Image image);//Ali Sayed Khamees
//Image Invert_Filter;//Mohamed Hossam Abdelsamad
Image Frame_Filter(Image img);//Mohamed Ramy Mohamed
Image Flip_Filter(Image image , string state);//Abdelrahman Ahmed Elsayed
Image Rotate_image_filter(Image image,int rotated_angle);//Ali Sayed Khamees
//Image Darken_Lighten_Filter(Image image);//Mohamed Hossam Abdelsamad
Image Resize_Filter(Image img);//Mohamed Ramy Mohamed


int main (){

    cout << R"(╔════════════════════════════════════╗
║                                    ║
║     Welcome to our Image Editor    ║
║                                    ║
╚════════════════════════════════════╝
)";

    cout<<"Please enter the name of the image file you want to edit (with extension): ";
    string fileName;
    cin>>fileName;

    cout<<"Choose any filter from this menu: "<<endl;
    cout<<"1- Grayscale Conversion"<<endl;
    cout<<"2- Black & White"<<endl;
    cout<<"3- Invert Image"<<endl;
    cout<<"4- Adding Frame"<<endl;
    cout<<"5- Flip Image"<<endl;
    cout<<"6- Rotate Image"<<endl;
    cout<<"7- Darken & Lighten Image"<<endl;
    cout<<"8- Resizing Image"<<endl;
    cout<<"The number of the filter : ";

    int filterChoice;
    cin>>filterChoice;

    do{
        switch (filterChoice){

    case 1:{
            Image image(fileName);
            Image Filtered_Image = GrayScale_Filter(image);
            string finalFileName = "grayscale_" + fileName;
            Filtered_Image.saveImage(finalFileName);
        break;
    }
    case 2:{
            Image image(fileName);
            Image Filtered_Image = Black_and_White_filter(image);
            string finalFileName = "black_and_white_" + fileName;
            Filtered_Image.saveImage(finalFileName);
        break;
    }
    case 3:{
            // Image image(fileName);
            // Image Filtered_Image = Invert_Filter(image);
            // string finalFileName = "inverted_" + fileName;
            // Filtered_Image.saveImage(finalFileName);
        break;
    }
    case 4:{
            Image image(fileName);
            Image Filtered_Image = Frame_Filter(image);
            string finalFileName = "framed_" + fileName;
            Filtered_Image.saveImage(finalFileName);
        break;
    }
    case 5:{
            Image image(fileName);

            cout<<"================================";
            cout<<"[0] vertical";
            cout<<"[1] horizontal";
            cout<<"================================";
            string state;
            cin>>state;

            while(state != "0" && state != "1"){
                  cout << "Invalid choice. Please enter 0 or 1: ";
                  cin >> state;
           }

           if(state == "0") state = "vertical";
              else state = "horizontal";

           Image Flipped_Image = Flip_Filter(image, state);
           string finalFileName = "flipped_" + state + "_" + fileName;
           Flipped_Image.saveImage(finalFileName);
           break;
    }
    case 6:{
            Image image(fileName);
            int rotated_angle;
            cout<<"Enter the angle of rotation (90, 180, or 270 degrees): ";
            cin>>rotated_angle;

            Image Rotated_Image = Rotate_image_filter(image, rotated_angle);
            string finalFileName = "rotated_" + to_string(rotated_angle) + "_" + fileName;
            Rotated_Image.saveImage(finalFileName);
            cout<<image.width<<'\n';
            cout<<image.height<<'\n';
        break;
    }
    case 7:{
            // Image image(fileName);
            // Image Filtered_Image = Darken_Lighten_Filter(image);
            // string finalFileName = "darkened_or_lightened_" + fileName;
            // Filtered_Image.saveImage(finalFileName);
        break;
    }
    case 8:{
            Image image(fileName);
            Image Filtered_Image = Resize_Filter(image);
            string finalFileName = "resized_" + fileName;
            Filtered_Image.saveImage(finalFileName);
        break;
    }
    default:
        cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
        break;
    }
    }while (filterChoice < 1 || filterChoice > 8);
}



//Filter Functions

//1- Grayscale Conversion
Image GrayScale_Filter(Image image){

    for(int i=0; i < image.width; ++i){
        for(int j=0; j < image.height; ++j){

            unsigned int avg_color = 0;

            for(int k=0; k < image.channels; ++k){
                avg_color += image(i, j, k);
            }

            avg_color /= image.channels;

            image.setPixel(i, j, 0, avg_color);
            image.setPixel(i, j, 1, avg_color);
            image.setPixel(i, j, 2, avg_color);

        }
    }

    return image;
}

//2- Black & White

Image Black_and_White_filter(Image image){

    GrayScale_Filter(image);

    int threshold=128; // The threshold is a value used to determine whether the pixel will become black or white.
    
    
    for(int i=0;i<image.width;i++){
        for(int j=0;j<image.height;j++){
            int value;

            if(image(i,j,0)<threshold) value=0;  // here we take the channel 0 as the three channels have the same value of Gray_color
            
            else value=255;

            

            for(int k=0;k<3;k++){
                image(i,j,k)=value;
            }

        }
    }

    return image;

}

//3- Invert Image

//4- Adding Frame

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

//5- Flip Image

Image Flip_Filter(Image image , string state){

    Image new_image(image.width , image.height);

    for(int i=0; i < image.width; ++i){
        for(int j=0; j < image.height; ++j){
            for(int k=0; k < image.channels; ++k)
                if(state == "vertical")
                    new_image(image.width - 1 - i, j, k) = image(i, j, k);
                else if (state == "horizontal")
                    new_image(i, image.height - 1 - j, k) = image(i, j, k);
        }
    }

    return new_image;
}

//6- Rotate Image

Image Rotate_image_filter(Image image,int rotated_angle){

    if(rotated_angle==90){
        Image new_image(image.height,image.width);
        int H=image.height;

        for(int i=0;i<image.width;i++){
            for(int j=0;j<image.height;j++){
                for(int k=0;k<3;k++){
                    new_image(H-1-j,i,k)=image(i,j,k);
                }
            }
        }

        return new_image;

    }

    else if(rotated_angle==180){
        Image new_image(image.width,image.height);

        int H=image.height;
        int W=image.width;

        for(int i=0;i<image.width;i++){
            for(int j=0;j<image.height;j++){
                for(int k=0;k<3;k++){
                    new_image(W-1-i,H-1-j,k)=image(i,j,k);
                }
            }
        }

        return new_image;

    }

    else if (rotated_angle==270){
        Image new_image(image.height,image.width);

        int W=image.width;

        for(int i=0;i<image.width;i++){
            for(int j=0;j<image.height;j++){
                for(int k=0;k<3;k++){
                    new_image(j,W-1-i,k)=image(i,j,k);
                }
            }
        }

        return new_image;

    }
    else{
        cout<<"This image cannot be rotated by that angle"<<endl;
    }
    return image;

    
}


//7- Darken & Lighten Image

//8- Resizing Image

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