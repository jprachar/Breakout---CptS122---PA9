#include "libs.h"
#include "Ball.h"
#include "Brick.h"
#include "Collisions.h"
#include "Paddle.h"
#include "Score.h"
#include <time.h>

int main(void)
{
	int isVictory = 0;
	int isLost = 0;
	int score = 0;
	double speed = 5;
	double dx = 0;
	double dy = 0;

	int menu_option = 0;

	//create window
	sf::RenderWindow window(sf::VideoMode(800, 700), "Breakout! Hint: Arrow Keys");
	window.setFramerateLimit(60);

	//creat font
	sf::Font font;
	font.loadFromFile("Roboto-Black.ttf");
	sf::Text rules;
	sf::Text Score;

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
						if (menu_option == SEE_RULES)
						{
							while (window.isOpen())
							{
								rules.setFont(font);
								rules.setString("Smash all the blocks!\n"
									"[space] to launch the ball\n"
									"Arrow keys to move your paddle\n\n"
									"Each Ball brick collision causes 1 pt health damage to bricks\n"
									"Blue Bricks = 1 hp\n"
									"Green Bricks  = 2 hp\n"
									"Red Bricks   = 3 hp\n\n\n"
									"Press Escape to go back to menu");

								//if enter
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
								{
									menu_option = 0;
									break;
								}


								//close window
								sf::Event event;
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();
								}

								//render
								window.clear();
								window.draw(rules);
								window.display();
							}
						}
						break;
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



	//play game
	if (menu_option == PLAY)
	{
		//create ball shape
		Ball ball{ 800 / 2 , 700 / 2 };

		//create paddle shape
		Paddle player{ 350, 656 };

		std::vector<Brick> bricks;

		for (int iX{ 0 }; iX < 6; ++iX)
		{
			for (int iY{ 0 }; iY < 4; ++iY)
			{
				bricks.emplace_back((iX + 1) * (100 + 10) + 20, (iY + 2) * (25 + 3));
			}
		}

		//sf::CircleShape shape(100.f);
		//shape.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{

			//detect Ball/Paddle collision
			if (Intersecting(ball, player))
			{
					ball.velocity.y = -speed;

				if (ball.x() < player.x())
				{
					ball.velocity.x = -speed;
				}
				else
				{
					ball.velocity.x = speed;
				}
			}

			//detect Ball/Brick collision
			for (auto& brick : bricks)
			{
				if (Intersecting(brick, ball))
				{
					Collision(brick, ball);
					score++;
				}
			};

			//move objects
			ball.update();
			player.update();

			//input detection
				//release ball
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				ball.velocity.x = speed;
				ball.velocity.y = speed;
				score = 0;
			}

				//close window
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			bricks.erase(std::remove_if(begin(bricks), end(bricks), [](const Brick& Brick) {return Brick.destroyed; }), end(bricks));

			//render
			window.clear();
			window.draw(ball.shape);
			window.draw(player.shape);
			Score.setFont(font);
			Score.setString(std::to_string(score));
			Score.setCharacterSize(24);
			Score.setFillColor(sf::Color::Yellow);
			for (auto& brick : bricks)
			{
				window.draw(brick.shape);
			}

			//victory
			if (bricks.empty())// all brick been smashed
			{
				isVictory = 1;
				break;
			}

			//you loose
			if (ball.y() > player.y() + 11)
			{
				isLost = 1;
				break;
			}

			//draw text
			window.draw(Score);
			window.display();
		}

		//goes into via flag
		if (isVictory)
		{
			sf::Text victory;
			victory.setFont(font);
			victory.setCharacterSize(100);
			victory.setString("You WIN");
			victory.setFillColor(sf::Color::Green);
			window.clear();
			window.draw(victory);
			window.display();
			Sleep(3000);
			window.close();
		}

		if (isLost)
		{
			sf::Text lost;
			lost.setFont(font);
			lost.setCharacterSize(100);
			lost.setString("You LOSE");
			lost.setFillColor(sf::Color::Red);
			window.clear();
			window.draw(lost);
			window.display();
			Sleep(3000);
			window.close();
		}
	}

	//Write Score to File
	Score1 Writescore(score);

	return 0;
}
