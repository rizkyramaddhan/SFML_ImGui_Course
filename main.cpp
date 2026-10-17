#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

int main() {

    sf::RenderWindow Window(sf::VideoMode(sf::Vector2u(1280,720)), "Engine Game Saya");
    Window.setFramerateLimit(60);

    while(Window.isOpen()){

        while(const std::optional<sf::Event> eventGame = Window.pollEvent()){
            if(eventGame->is<sf::Event::Closed>()){
                Window.close();
            }
        }

        Window.clear(sf::Color::Blue);
        Window.display();
    }

    return 0;
}