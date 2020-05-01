#include "libs.h"

struct Ball
{
	sf::CircleShape shape;

	sf::Vector2f velocity{ 0, 0 };

	Ball(float x, float y)
	{
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(350, 640);
		shape.setRadius(7.f);
		shape.setOrigin(7.f,7.f);
	};

	float x() { return shape.getPosition().x; };
	float y() { return shape.getPosition().y; };
	float left() { return x() - shape.getRadius(); };
	float right() { return x() + shape.getRadius(); };
	float top() { return y() - shape.getRadius(); };
	float bottom() { return y() + shape.getRadius(); };

	void update() { 
		shape.move(velocity); 
		if (left() < 0)
		{
			velocity.x = 5;

		}
		else if (right() > 800)
			velocity.x = -5;
		else if (top() < 0)
			velocity.y = 5;
	};
};

