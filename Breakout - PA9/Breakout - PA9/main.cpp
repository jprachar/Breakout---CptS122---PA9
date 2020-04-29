#include "libs.h"

int main(void)
{
	int score = 0;
	double speed = 5;
	double dx = 0;
	double dy = 0;

	int menu_option = 0;

	//create window
	sf::RenderWindow window(sf::VideoMode(700, 700), "Breakout!         Hint: Use the arrow keys");
	window.setFramerateLimit(60);

	//create menu
	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen() && menu_option == 0)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						menu_option = PLAY;
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						menu_option = SEE_RULES;
						std::cout << "Show Rules button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}


	//creat font
	sf::Font font;
	font.loadFromFile("Roboto-Black.ttf");

	//play game
	if (menu_option == PLAY)
	{
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
			if (ballPos.x < 0) dx = speed;
			else if (ballPos.x > 700 - 10) dx = -speed;
			if (ballPos.y < 0) dy = speed;
			else if (ballPos.y > 700 - 10)
			{
				dx = 0;
				dy = 0;
			}

			if (ballPos.x >= playerPos.x && ballPos.x <= playerPos.x + 70)
			{
				if (ballPos.y >= playerPos.y - 10)
				{
					dy = -speed;
				}
			}

			//move ball
			ball.move(dx, dy);

			//input detection
				//release ball
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				dx = speed;
				dy = speed;
				score = 0;
			}

			//move left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				if (playerPos.x > 0)
					player.move(-speed, 0);

			//move right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				if (playerPos.x < 700 - 70) // need to make this static varible
					player.move(speed, 0);

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
			//draw text
			window.display();

		}
	}



	

	return 0;
}