//
//  ASKII.cpp
//  ASKII_SFML
//
//  Created by Dell on 20.01.2023.
//

#include "ASKII2.hpp"
#include <math.h>


namespace askii {

void recieveMessege(ASKII_ALGORITHM& askii,std::string &recieved_string){
    if(askii.cur_image.loadFromFile(recieved_string)){
        std::cout<<"Yay, image loaded\n";
    }
}



ASKII_ALGORITHM::ASKII_ALGORITHM(std::string path)
{
    if(cur_image.loadFromFile(path)){
       std::cout<<"Yay, image loaded\n";
    }
    this->path = path;
    size = cur_image.getSize();
    image_string = new std::string[size.y];
    for (int i = 0; i < size.y; i++){
        image_string[i] = (char)('1' + i);
    }

};

ASKII_ALGORITHM::~ASKII_ALGORITHM(){
    
}

void ASKII_ALGORITHM::convert_to_gray(){
    int ser;
    for (int y = 0; y<size.y;y++) {
        for (int x =0 ; x<size.x; x++) {
            ser = int(cur_image.getPixel(x,y).r * 0.299 +cur_image.getPixel(x,y).g * 0.587 +cur_image.getPixel(x,y).b * 0.114);
            cur_image.setPixel(x,y, sf::Color(ser,ser,ser));
        }
    }
    cur_image.saveToFile("../result/result.png");
}

void ASKII_ALGORITHM::convert_to_aski() {
    //scale(0.25);
    askii_algorithm();
}




void ASKII_ALGORITHM::contrast(){
   
    int factorR,factorG,factorB;
    int minIntensityR = find_min_intensity('r');
    int minIntensityG = find_min_intensity('g');
    int minIntensityB = find_min_intensity('b');
    
    int maxIntensityR = find_max_intensity('r');
    int maxIntensityG = find_max_intensity('g');
    int maxIntensityB = find_max_intensity('b');
    for (int y = 0; y<size.y;y++) {
        for(int x =0 ; x<size.x; x++){
            factorR = std::abs(int((cur_image.getPixel(x,y).r -minIntensityR)*(255/(maxIntensityR-minIntensityR))));
            factorG = std::abs(int((cur_image.getPixel(x,y).g -minIntensityG)*(255/(maxIntensityG-minIntensityG))));
            factorB = std::abs(int((cur_image.getPixel(x,y).b -minIntensityB)*(255/(maxIntensityB-minIntensityB))));
            
            cur_image.setPixel(x, y, sf::Color(factorR,factorG,factorB));
        }
    }
    
    cur_image.saveToFile("../result/result.png");
    
}

int ASKII_ALGORITHM::find_max_intensity(char chanel) {
    int result =0;
    switch (chanel) {
        case 'r':{
            result = cur_image.getPixel(0, 0).r;
            for (int y = 0; y<size.y;y++) {
                for (int x =0 ; x<size.x; x++) {
                    if(cur_image.getPixel(x, y).r > result){
                        result = cur_image.getPixel(x, y).r;
                    }
                }
            }
            
            break;
        }
        case 'g':{
            result = cur_image.getPixel(0, 0).g;
            for (int y = 0; y<size.y;y++) {
                for (int x =0 ; x<size.x; x++) {
                    if(cur_image.getPixel(x, y).g > result){
                        result = cur_image.getPixel(x, y).g;
                    }
                }
            }
            break;
        }case 'b':{
            result = cur_image.getPixel(0, 0).b;
            for (int y = 0; y<size.y;y++) {
                for (int x =0 ; x<size.x; x++) {
                    if(cur_image.getPixel(x, y).b > result){
                        result = cur_image.getPixel(x, y).b;
                    }
                }
            }
            break;
        }
        default:
            break;
    }
    return result;
}


int ASKII_ALGORITHM::find_min_intensity(char chanel) {
    int result =0;
    switch (chanel) {
        case 'r':{
            result = cur_image.getPixel(0, 0).r;
            for (int y = 0; y<size.y;y++) {
                for (int x =0 ; x<size.x; x++) {
                    if(cur_image.getPixel(x, y).r < result){
                        result = cur_image.getPixel(x, y).r;
                    }
                }
            }
            
            break;
        }
        case 'g':{
            result = cur_image.getPixel(0, 0).g;
            for (int y = 0; y<size.y;y++) {
                for (int x =0 ; x<size.x; x++) {
                    if(cur_image.getPixel(x, y).g < result){
                        result = cur_image.getPixel(x, y).g;
                    }
                }
            }
            break;
        }case 'b':{
            result = cur_image.getPixel(0, 0).b;
            for (int y = 0; y<size.y;y++) {
                for (int x =0 ; x<size.x; x++) {
                    if(cur_image.getPixel(x, y).b < result){
                        result = cur_image.getPixel(x, y).b;
                    }
                }
            }
            break;
        }
        default:
            break;
    }
    return result;
}

void ASKII_ALGORITHM::askii_algorithm() {
    cur_image.loadFromFile(path);
    /*file.open("../result/askii/result.txt");
    if(file.is_open()){
        std::cout<<"file opened sucessfuly\n";
    }else{
        return;
    }*/
    std::string symbols = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$;//{ '@', '%', '#', 'x', '+', '=', ':', '-', '.', ' ' }";
    int saturation;
    double greyscale;
    int lenght = symbols.size() -1;
    char symbol;
    for (int y = 0; y<size.y; y++) {
        for (int x = 0; x<size.x; x++){
            
            symbol = '\0';
            greyscale = cur_image.getPixel(x,y).r * 0.299 + cur_image.getPixel(x,y).g * 0.587 +cur_image.getPixel(x,y).b * 0.114;
            saturation = int((greyscale/255.0 )*(lenght));
            
            
            
            symbol = symbols[saturation];
            image_string[y]+=symbol;
        }
    }
    
    
}

int ASKII_ALGORITHM::get_pixel_intensity(sf::Vector2u amount_of_pixels) {
    int sum = 0;
    for (int y = 0; y < amount_of_pixels.y; y++) {
        for (int x = 0; x < amount_of_pixels.x; x++) {
            sum += cur_image.getPixel(x, y).r + cur_image.getPixel(x, y).g + cur_image.getPixel(x, y).b;
        }
    }
    return sum ;
}


void ASKII_ALGORITHM::scale(float faсtor) {
    sf::Image tmp;
    if(faсtor >= 1 && faсtor > 0){
        tmp.create(size.x * faсtor, size.y * faсtor);
        int x_nearest,y_nearest;
        sf::Color pixel;
        for (int y = 0; y < tmp.getSize().y; y++) {
            for (int x = 0; x < tmp.getSize().x; x++) {
                x_nearest = int(round(x/faсtor));
                y_nearest = int(round(y/faсtor));
                pixel = cur_image.getPixel(x_nearest, y_nearest);
                tmp.setPixel(x, y, pixel);
            }
        }
        size.x = tmp.getSize().x;
        size.y = tmp.getSize().y;
    }else if(faсtor < 1 && faсtor > 0){
        tmp.create(size.x * faсtor, size.y * faсtor);
        int x_nearest,y_nearest;
        sf::Color pixel;
        for (int y = 0; y < cur_image.getSize().y; y++) {
            for (int x = 0; x < cur_image.getSize().x; x++) {
                x_nearest = int(round(x * faсtor));
                y_nearest = int(round(y * faсtor));
                pixel = cur_image.getPixel(x, y);
                tmp.setPixel(x_nearest, y_nearest, pixel);
            }
        }
        size.x = tmp.getSize().x;
        size.y = tmp.getSize().y;
    }
    cur_image.create(size.x, size.y, tmp.getPixelsPtr());
    cur_image.copy(tmp, size.x, size.y);
    cur_image.saveToFile("../result/sacling_res.png");
}

char* ASKII_ALGORITHM::get_askii_array() {
    char line[94];
    
    for (unsigned char i =33,j = 0; i<127; i++,j++) {
        line[j] = i;
    }
    return line;
}







}
