#include <SFML/Graphics.hpp>



int main()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);

    float x = 200;
    float y = 200;
    
    shape.setPosition({x,y});

    const float speed = 5.0;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        Movement(x, y, speed);

        window.clear();
        window.draw(shape);
        window.display();
    }

}

void Movement(float &x, float &y, float speed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        y += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        x += speed;
    }
}