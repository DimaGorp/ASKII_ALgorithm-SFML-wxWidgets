#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


int main(){
    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(500,500),"It works");
    sf::CircleShape circle(5.0f);
    circle.setFillColor(sf::Color::Green);
    while (window->isOpen())
    {
        sf::Event ev;
        while (window->pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed){
                window->close();
            }
        }
        window->clear(sf::Color::White);
        window->draw(circle);
        window->display();
        
    }
    
    return 0;
}