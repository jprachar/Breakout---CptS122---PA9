#pragma once
struct Brick
{
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
