class RectangleBase
{
public:
	sf::RectangleShape shape;

	RectangleBase(float x, float y, float width, float height)
	{
		shape.setPosition(x, y);
		shape.setSize(sf::Vector2f(width, height));
	}

	float x() { return shape.getPosition().x; };
	float y() { return shape.getPosition().y; };
	float left() { return x() - shape.getSize().x / 2.f; };
	float right() { return x() + shape.getSize().x / 2.f; };
	float top() { return y() - shape.getSize().y / 2.f; };
	float bottom() { return y() + shape.getSize().y / 2.f; };
};

class Brick : public RectangleBase
{
public:
	bool destroyed{ false };
	int Armor = 0;
	Brick(float x, float y):RectangleBase(x,y,100.f,25.f)
	{
		int check = rand() % 3 + 1;

		if (check == 1)
		{
			shape.setFillColor(sf::Color::Blue);
			shape.setOrigin(sf::Vector2f(100 / 2, 50 / 2));
		}
		else if (check == 2)
		{
			shape.setFillColor(sf::Color::Green);
			shape.setOrigin(sf::Vector2f(100 / 2, 50 / 2));
			Armor = 1;
		}
		else
		{
			shape.setFillColor(sf::Color::Red);
			shape.setOrigin(sf::Vector2f(100 / 2, 50 / 2));
			Armor = 2;
		}
	}

};

class Paddle : public RectangleBase
{
public:
	sf::Vector2f velocity{ 0, 0 };

	Paddle(float x, float y):RectangleBase(x,y,70,10)
	{
		shape.setFillColor(sf::Color::White);
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
};
