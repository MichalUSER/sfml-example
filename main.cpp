#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;

int main()
{
	float shapeWidth;
	float shapeHeight;
	float xpos = 390.f;
	float ypos = 100.f;
	float speed = 9.f;
	float spaceAround = 15.f;
	sf::RenderWindow window(sf::VideoMode(900, 500), "SFML Example");
	window.setFramerateLimit(60.f);

	sf::Font font;
	if(!font.loadFromFile("roboto.ttf"))
	{
		cout << "Cannot open font\n";
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Click Me!");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	shapeWidth = text.getLocalBounds().width + spaceAround * 2;
	shapeHeight = text.getLocalBounds().height + spaceAround * 2;
	text.setPosition(sf::Vector2f(xpos + spaceAround, ypos + spaceAround));

	sf::RectangleShape shape(sf::Vector2f(shapeWidth, shapeHeight));
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
	text.setPosition(sf::Vector2f(xpos + spaceAround, ypos + spaceAround));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			ypos -= speed;
			shape.setPosition(sf::Vector2f(xpos, ypos));
			text.setPosition(sf::Vector2f(xpos + spaceAround, ypos + spaceAround));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			xpos -= speed;
			shape.setPosition(sf::Vector2f(xpos, ypos));
			text.setPosition(sf::Vector2f(xpos + spaceAround, ypos + spaceAround));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			xpos += speed;
			shape.setPosition(sf::Vector2f(xpos, ypos));
			text.setPosition(sf::Vector2f(xpos + spaceAround, ypos + spaceAround));
		}

		shape.setFillColor(sf::Color(238, 82, 83));
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			if(mousePosition.x > xpos && mousePosition.x < xpos + shapeWidth)
			{
				if(mousePosition.y > ypos && mousePosition.y < ypos + shapeHeight)
				{
					shape.setFillColor(sf::Color(255, 107, 107));
				}
			}
		}

		window.clear();
		window.draw(shape);
		window.draw(text);
		window.display();
	}

	return 0;
}
