#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

int main() {

    // Start Window Game
    unsigned int WindowWidth = 1280;
    unsigned int WindowHeight = 720; 
    sf::RenderWindow Window(sf::VideoMode(sf::Vector2u(WindowWidth,WindowHeight)), "Engine Game Saya");
    Window.setFramerateLimit(60);
    // End Window Game

    // Start Object Shape
    sf::Color Color = sf::Color::Blue;
    sf::RectangleShape Rumah(sf::Vector2f(100.0f, 100.0f));
    Rumah.setPosition(sf::Vector2f(200.0f, 200.0f));
    Rumah.setFillColor(sf::Color::Black);
    // End Object Shape

    // Start Texture Object
    sf::Texture texturePlayer;
    if(!texturePlayer.loadFromFile("Tank2-BirdView.png")){
        std::cout << "Failed to load texture" << std::endl;
        return -1;
    }
    // texturePlayer.setSmooth(true);
    sf::Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(sf::Vector2f(50.0f, 50.0f));
    spritePlayer.setScale(sf::Vector2f(0.5f, 0.5f));
    
    // End Texture Object

    // Start Main Loop
    while(Window.isOpen()){

        // Start Event Update 
        while(const std::optional<sf::Event> eventGame = Window.pollEvent()){
            if(eventGame->is<sf::Event::Closed>()){
                Window.close();
            }

            if(const auto * keyEvent = eventGame->getIf<sf::Event::KeyPressed>()){
                if(keyEvent->code == sf::Keyboard::Key::Escape){
                    Window.close();
                }else if(keyEvent->code == sf::Keyboard::Key::R){
                    Color = sf::Color::Red;
                }else if(keyEvent->code == sf::Keyboard::Key::G){
                    Color = sf::Color::Green;
                }else if(keyEvent->code == sf::Keyboard::Key::B){
                    Color = sf::Color::Blue;
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            spritePlayer.move(sf::Vector2f(0.0f, -0.1f));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            spritePlayer.move(sf::Vector2f(0.0f, 0.1f));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            spritePlayer.move(sf::Vector2f(-0.1f, 0.0f));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            spritePlayer.move(sf::Vector2f(0.1f, 0.0f));
        }
        // End Event Update

        // Start Draw Update
        Window.clear(Color);
        Window.draw(spritePlayer);
        Window.draw(Rumah);

        Window.display();
        // End Draw Update
    }
    // End Main Loop

    return 0;
}