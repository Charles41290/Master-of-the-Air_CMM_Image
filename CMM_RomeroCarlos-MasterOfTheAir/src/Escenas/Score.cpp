#include "Score.h"

Score::Score(int score)
{
	sampleFont.loadFromFile("res\\fonts\\SourGummy-Light.ttf");
	scoreText.setFont(sampleFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(sf::Color::Red);
	sf::FloatRect auxRect = scoreText.getGlobalBounds();
	scoreText.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	scoreText.setPosition(70,690);

}

void Score::Update(sf::Time deltaTime, int score)
{
	scoreText.setString("Score: " + std::to_string(score));
}

void Score::Draw(sf::RenderWindow* window)
{
	window->draw(scoreText);
}
