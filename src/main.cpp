#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>

// Inisialisasi Class Object

class gameEngine {
    // Start Variabels or Properties Class Object
    private :
        sf::RenderWindow window;
        sf::Color ColorBackground;
        unsigned int windowWidth;
        unsigned int windowHeight;
        std::string titleWindow;
        sf::RectangleShape kotak;   
        
        std::optional<sf::Texture> textureTank;
        std::optional<sf::Sprite> spriteTank;

    // End Variabels or Properties Class Object

    // Start construktor and method public class object
    public :
        gameEngine(unsigned int windowWidth, unsigned int windowHeight, std::string titleWindow) : window(sf::VideoMode(sf::Vector2u(windowWidth, windowHeight)), titleWindow)
        {
            window.setFramerateLimit(60);
            ColorBackground = sf::Color::Black;

            kotak.setSize(sf::Vector2f(100.0f, 100.0f));
            kotak.setPosition(sf::Vector2f(100.0f, 100.0f));
            kotak.setFillColor(sf::Color::White);

            textureTank.emplace();
            if(!textureTank->loadFromFile("Tank2-BirdView.png")){
                std::cout << "Error Load Texture" << std::endl;
            }

            spriteTank.emplace(*textureTank);
            spriteTank->setScale(sf::Vector2f(0.2f, 0.2f));
            spriteTank->setPosition(sf::Vector2f(200.0f, 200.0f));
            
        }

        void run(){
            while(window.isOpen()){
                eventUpdate();
                logicUpdate();
                renderUpdate();
            }
        }

    // End construktor and method public class object

    // start method private class object
    private :
        void eventUpdate(){
            while(const std::optional<sf::Event> events = window.pollEvent()){
                if(events->is<sf::Event::Closed>()){
                    window.close();
                }

                if(const auto * keyPressed = events->getIf<sf::Event::KeyPressed>()){
                    if(keyPressed->code == sf::Keyboard::Key::R){
                        ColorBackground = sf::Color::Red;
                    }else if(keyPressed->code == sf::Keyboard::Key::G){
                        ColorBackground = sf::Color::Green;
                    }
                }
                
            }
        }

        void logicUpdate(){
            // Start Kotak Move
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
                kotak.move(sf::Vector2f(0.0f, -5.0f));
            }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                kotak.move(sf::Vector2f(0.0f, 5.0f));
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                kotak.move(sf::Vector2f(-5.0f, 0.0f));
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                kotak.move(sf::Vector2f(5.0f, 0.0f));
            }
            // End Kotak Move


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
                spriteTank->move(sf::Vector2f(0.0f, -5.0f));
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
                spriteTank->move(sf::Vector2f(0.0f, 5.0f));
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                spriteTank->move(sf::Vector2f(-5.0f, 0.0f));
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                spriteTank->move(sf::Vector2f(5.0f, 0.0f));
            }

            

        }

        void renderUpdate(){
            window.clear(ColorBackground);

            window.draw(kotak);
            window.draw(*spriteTank);

            window.display();
        }
    // end method private class object
};


int main(){
    gameEngine game(800,600, "Game Engine v0.3");
    game.run();
    return 0;
}