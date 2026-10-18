#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

int main() {

    sf::RenderWindow Window(sf::VideoMode(sf::Vector2u(1280,720)), "Engine Game Saya");
    Window.setFramerateLimit(60);

    sf::Color Color = sf::Color::Blue;
    sf::RectangleShape Kotak(sf::Vector2f(50.0f, 50.0f));
    Kotak.setFillColor(sf::Color::Black);
    Kotak.setPosition(sf::Vector2f(100.0f, 100.0f));

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
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            Kotak.move(sf::Vector2f(0.0f, -10.0f));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            Kotak.move(sf::Vector2f(0.0f, 10.0f));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            Kotak.move(sf::Vector2f(-10.0f, 0.0f));
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            Kotak.move(sf::Vector2f(10.0f, 0.0f));
        }

        Window.clear(Color);

        Window.draw(Kotak);

        Window.display();
    }

    return 0;
}