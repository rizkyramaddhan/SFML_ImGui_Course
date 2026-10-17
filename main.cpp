#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

int main() {

    sf::RenderWindow Window(sf::VideoMode(sf::Vector2u(1280,720)), "Engine Game Saya");
    Window.setFramerateLimit(60);

    sf::Color Color = sf::Color::Blue;

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

        Window.clear(Color);
        Window.display();
    }

    return 0;
}