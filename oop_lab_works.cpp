#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Lab");
    window.setFramerateLimit(60);
    sf::Event event{};
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
        }
    }
    return 0;
}
