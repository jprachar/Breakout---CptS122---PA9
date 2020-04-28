#include "libs.h"

int main(void)
{
	//create window
	sf::RenderWindow window(sf::VideoMode(700, 700), "Breakout!");
	window.setFramerateLimit(60);

	//creat font
	sf::Font font;
	font.loadFromFile("Roboto-Black.ttf");


	//create ball shape
	sf::CircleShape ball(7.f);
	ball.setFillColor(sf::Color::Green);
	ball.setPosition(350, 640);

	//create paddle shape
	sf::RectangleShape player(sf::Vector2f(70, 10));
	player.setFillColor(sf::Color::White);
	player.setPosition(322, 656);




	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Vector2f ballPos = ball.getPosition();
		sf::Vector2f playerPos = player.getPosition();

		//detect collisions

		//move ball

		//input detection

			//close window
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//render
		window.clear();
		window.draw(ball);
		window.draw(player);
		window.display();



	}
//	sf::RenderWindow window(sf::VideoMode(600, 972), "Breakout");

	return 0;
}