#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;

int main()
{
	float xpos = 390.f;
	float ypos = 100.f;
	float speed = 9.f;
	sf::RenderWindow window(sf::VideoMode(900, 500), "SFML Example");
	window.setFramerateLimit(60.f);

	sf::RectangleShape shape(sf::Vector2f(120.f, 50.f));
	shape.setFillColor(sf::Color(238, 82, 83));
	shape.setPosition(sf::Vector2f(xpos, ypos));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			ypos += speed;
			shape.setPosition(sf::Vector2f(xpos, ypos));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			ypos -= speed;
			shape.setPosition(sf::Vector2f(xpos, ypos));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			xpos -= speed;
			shape.setPosition(sf::Vector2f(xpos, ypos));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			xpos += speed;
			shape.setPosition(sf::Vector2f(xpos, ypos));
		}

		shape.setFillColor(sf::Color(238, 82, 83));
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			if(mousePosition.x > xpos && mousePosition.x < xpos + 120)
			{
				if(mousePosition.y > ypos && mousePosition.y < ypos + 50)
				{
					shape.setFillColor(sf::Color(255, 107, 107));
				}
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
