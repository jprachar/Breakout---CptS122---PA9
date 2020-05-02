#include "libs.h"

class Brick
{
public:
	sf::RectangleShape shape;
	bool destroyed{ false };
	Brick(float x, float y)
	{
		shape.setPosition(x, y);
		shape.setSize(sf::Vector2f(100.f, 25.f));
		shape.setFillColor(sf::Color::Blue);
		shape.setOrigin(sf::Vector2f(100 / 2, 50 / 2));
	}

	float x() { return shape.getPosition().x; };
	float y() { return shape.getPosition().y; };
	float left() { return x() - shape.getSize().x / 2.f; };
	float right() { return x() + shape.getSize().x / 2.f; };
	float top() { return y() - shape.getSize().y / 2.f; };
	float bottom() { return y() + shape.getSize().y / 2.f; };
};

class Paddle : public Brick
{
public:
	sf::RectangleShape shape;
	sf::Vector2f velocity{ 0, 0 };

	Paddle(float x, float y) : Brick(x, y)
	{
		shape.setSize(sf::Vector2f(70, 10));
		shape.setFillColor(sf::Color::White);
		shape.setPosition(x, y);
		shape.setOrigin(70 / 2, 10 / 2);
	}

	void update() {
		shape.move(velocity);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && left() > 0)
		{
			velocity.x = -8;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && right() < 800)
			velocity.x = 8;
		else
			velocity.x = 0;

	};

	float x() { return shape.getPosition().x; };
	float y() { return shape.getPosition().y; };
	float left() { return x() - shape.getSize().x / 2.f; };
	float right() { return x() + shape.getSize().x / 2.f; };
	float top() { return y() - shape.getSize().y / 2.f; };
	float bottom() { return y() + shape.getSize().y / 2.f; };
};
