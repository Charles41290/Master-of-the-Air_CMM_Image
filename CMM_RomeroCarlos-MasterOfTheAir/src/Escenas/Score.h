#pragma once
#include <SFML/Graphics.hpp>
class Score
{
protected:
	sf::Text scoreText;
	sf::Font sampleFont;
	
public:
	Score(int score);
	void Update(sf::Time deltaTime, int score);
	void Draw(sf::RenderWindow* window);
};

