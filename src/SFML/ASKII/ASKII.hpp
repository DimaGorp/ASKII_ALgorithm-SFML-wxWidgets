//
//  ASKII.hpp
//  ASKII_SFML
//
//  Created by Dell on 20.01.2023.
//

#ifndef ASKII_hpp
#define ASKII_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <fstream>

namespace image_pre_processing {
int boundedPixelValue(sf::Color color,float brightnessFactor);
}

namespace askii {
class ASKII_ALGORITHM{
    friend void recieveMessege(ASKII_ALGORITHM& askii,std::string &recieved_string);
    sf::Image cur_image;
    sf::Vector2u size;
    void convert_to_gray();
    void contrast();
    int find_min_intensity(char chanel);
    int find_max_intensity(char chanel);
    void askii_algorithm(std::string path);
    char* get_askii_array();
    int get_pixel_intensity(sf::Vector2u amount_of_pixels);
    void scale(float factor);
public:
    ASKII_ALGORITHM();
    ~ASKII_ALGORITHM();
    void convert_to_aski(std::string path);
};

void recieveMessege(ASKII_ALGORITHM& askii,std::string &recieved_string);
}

#endif /* ASKII_hpp */
