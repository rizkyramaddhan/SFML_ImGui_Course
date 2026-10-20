#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
#include <optional>

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
        std::vector<sf::Sprite> vectorSpriteTank;

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

            for(int i = 0; i < 5; i++){
                vectorSpriteTank.emplace_back(* textureTank);
                vectorSpriteTank.back().setScale(sf::Vector2f(0.2f, 0.2f));
                vectorSpriteTank.back().setPosition(sf::Vector2f(i * 100.0f, 0.2f));
            }
            
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
            for(auto & tank : vectorSpriteTank){
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
                tank.move(sf::Vector2f(0.0f, -5.0f));
                }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    tank.move(sf::Vector2f(0.0f, 5.0f));
                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                    tank.move(sf::Vector2f(-5.0f, 0.0f));
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                    tank.move(sf::Vector2f(5.0f, 0.0f));
                }
            }
           

        }

        void renderUpdate(){
            window.clear(ColorBackground);

            window.draw(kotak);
            for(const auto & tank : vectorSpriteTank){
                window.draw(tank);
                
            }

            window.display();
        }
    // end method private class object
};


int main(){
    gameEngine game(800,600, "Game Engine v0.3");
    game.run();
    return 0;
}