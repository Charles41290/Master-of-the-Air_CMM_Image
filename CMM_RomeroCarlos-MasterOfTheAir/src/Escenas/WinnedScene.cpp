#include "WinnedScene.h"

WinnedScene::WinnedScene(sf::Vector2u windowSize)
{
	sampleFont.loadFromFile("res\\fonts\\SourGummy-Light.ttf");
	winnedText.setFont(sampleFont);
	winnedText.setString("GREAT JOB! YOU'RE A MASTER OF THE AIR");
	winnedText.setCharacterSize(70);
	winnedText.setFillColor(sf::Color::Red);
	sf::FloatRect auxRect = winnedText.getGlobalBounds();// utilizo un auxRect para centrar el título
	winnedText.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	winnedText.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));

	//sampleFont.loadFromFile("res\\fonts\\TADR.ttf");
	pressToContinueText.setFont(sampleFont);
	pressToContinueText.setString("[C] to continue");
	pressToContinueText.setCharacterSize(30);
	pressToContinueText.setFillColor(sf::Color::Magenta);
	auxRect = pressToContinueText.getGlobalBounds();// utilizo un auxRect para centrar el título
	pressToContinueText.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	pressToContinueText.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2 + 65));
}

WinnedScene::~WinnedScene()
{
}

void WinnedScene::Update(sf::Time deltaTime)
{
}

void WinnedScene::Draw(sf::RenderWindow* window)
{
	window->draw(winnedText);
	window->draw(pressToContinueText);
}
