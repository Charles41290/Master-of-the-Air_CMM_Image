#include "DefeatedScene.h"
#include "../Game.h"

DefeatedScene::DefeatedScene(sf::Vector2u windowSize, Game* game):game(game)
{
    sampleFont.loadFromFile("res\\fonts\\SourGummy-Light.ttf");
	defeatedText.setFont(sampleFont);
	defeatedText.setString("Defeated");
	defeatedText.setCharacterSize(70);       
	defeatedText.setFillColor(sf::Color::Red);
	sf::FloatRect auxRect = defeatedText.getGlobalBounds();// utilizo un auxRect para centrar el título
	defeatedText.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	defeatedText.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));

	pressToContinueText.setFont(sampleFont);
	pressToContinueText.setString("[C] to continue");
	pressToContinueText.setCharacterSize(30);
	pressToContinueText.setFillColor(sf::Color::Magenta);
	auxRect = pressToContinueText.getGlobalBounds();// utilizo un auxRect para centrar el título
	pressToContinueText.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	pressToContinueText.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2 + 65));

}

DefeatedScene::~DefeatedScene()
{
}

void DefeatedScene::Update(sf::Time deltaTime)
{
	
}

void DefeatedScene::Draw(sf::RenderWindow* window)
{
	window->draw(defeatedText);
	window->draw(pressToContinueText);
}
