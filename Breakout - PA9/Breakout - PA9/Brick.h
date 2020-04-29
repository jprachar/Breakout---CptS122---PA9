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

};
