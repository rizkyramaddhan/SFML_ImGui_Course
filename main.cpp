#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

int main() {

    sf::RenderWindow Window(sf::VideoMode(sf::Vector2u(1280,720)), "Engine Game Saya");
    Window.setFramerateLimit(60);

    float kotakX = 100.0f;
    float kotakY = 100.0f;

    sf::Color Color = sf::Color::Blue;
    sf::RectangleShape Kotak(sf::Vector2f(50.0f, 50.0f));
    Kotak.setFillColor(sf::Color::Black);
    Kotak.setPosition(sf::Vector2f(kotakX, kotakY));

    while(Window.isOpen()){

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
                }else if(keyEvent->code == sf::Keyboard::Key::Q){
                    std::cout << "Quit Game Saya" << std::endl;
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)){
            std::cout << "RRRRRRRRRRRRRR" << std::endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            kotakY -= 10.0f;
            Kotak.setPosition(sf::Vector2f(kotakX, kotakY));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            kotakY += 10.0f;
            Kotak.setPosition(sf::Vector2f(kotakX, kotakY));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            kotakX -= 10.0f;
            Kotak.setPosition(sf::Vector2f(kotakX, kotakY));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            kotakX += 10.0f;
            Kotak.setPosition(sf::Vector2f(kotakX, kotakY));
        }

        Window.clear(Color);

        Window.draw(Kotak);

        Window.display();
    }

    return 0;
}