template <class T1, class T2> bool Intersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

void Collision(Brick& Brick,  Ball& Ball)
{
	Brick.destroyed = true;

	float overlapleft { Ball.right() - Brick.left() };
	float overlapright{ Brick.right() - Ball.left() };
	float overlaptop{ Ball.bottom() - Brick.top() };
	float overlapbottom{ Brick.bottom() - Ball.top() };

	bool BallLeft(abs(overlapleft) < abs(overlapright));

	bool BallTop(abs(overlaptop) < abs(overlapbottom));

	float minoverlapX{ BallLeft ? overlapleft : overlapright };

	float minoverlapY{ BallTop ? overlaptop : overlapbottom };

	if (abs(minoverlapX) < abs(minoverlapY))
	{
		Ball.velocity.x = BallLeft ? -5 : 5;
	}
	else
	{
		Ball.velocity.y = BallTop ? -5 : 5;
	}
	
	if (Brick.Armor == 0)
	{
		Brick.shape.setFillColor(sf::Color::Blue);
	}
	else if (Brick.Armor == 1)
	{
		Brick.shape.setFillColor(sf::Color::Green);
	}
}
