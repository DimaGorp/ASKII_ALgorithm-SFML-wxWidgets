//
//  ASKII.hpp
//  ASKII_SFML
//
//  Created by Dell on 20.01.2023.
//

#ifndef ASKII_hpp
#define ASKII_hpp

#include <iostream>
#include <fstream>
#include <cstring>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace image_pre_processing {
int boundedPixelValue(sf::Color color,float brightnessFactor);
}

namespace askii {
class ASKII_ALGORITHM{
    friend void recieveMessege(ASKII_ALGORITHM& askii,std::string &recieved_string);
    sf::Image cur_image;
    sf::Vector2u size;
    std::ofstream file;
    std::string path;
    std::string *image_string;
    void convert_to_gray();
    void contrast();
    int find_min_intensity(char chanel);
    int find_max_intensity(char chanel);
    void askii_algorithm();
    char* get_askii_array();
    int get_pixel_intensity(sf::Vector2u amount_of_pixels);
    void scale(float factor);
public:
    ASKII_ALGORITHM(std::string path);
    std::string* getAskiiTable(){return image_string;}
    ~ASKII_ALGORITHM();
    sf::Vector2u getSize(){return size;}

    void convert_to_aski();
};

void recieveMessege(ASKII_ALGORITHM& askii,std::string &recieved_string);
}

#endif /* ASKII_hpp */
