#include "Tutorial.h"
#include "../Game.h"

Tutorial::Tutorial(sf::Vector2u windowSize, Game* game): game(game)
{
	sampleFont.loadFromFile("res\\fonts\\MigaeSemibold.otf");
	title.setFont(sampleFont);
	title.setString("Tutorial");
	title.setCharacterSize(50);       // Tamaño del texto en píxeles
	title.setFillColor(sf::Color::Yellow); // Color del texto
	sf::FloatRect auxRect = title.getGlobalBounds();// utilizo un auxRect para centrar el título
	title.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	title.setPosition(sf::Vector2f(windowSize.x / 2, 100));      // Posición en la ventana

	// Titulo
	sampleFont2.loadFromFile("res\\fonts\\SourGummy-Light.ttf");
	instruction1.setFont(sampleFont2);
	instruction1.setString("Press [A,W,S,D] to move. To shoot press [Spacebar]. To go back to Main Menu press [Q]\nTo Exit press [Esc] ");
	instruction1.setCharacterSize(20);
	instruction1.setFillColor(sf::Color::Green);
	auxRect = instruction1.getGlobalBounds();
	instruction1.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	instruction1.setPosition(sf::Vector2f(windowSize.x / 2, 200));

	// Instrucciones
	//sampleFont2.loadFromFile("res\\fonts\\SourGummy-Light.ttf");
	instruction2.setFont(sampleFont2);
	instruction2.setString("Be careful not to hit the walls or enemy ships and dont forget to avoid getting hit by enemy bullets");
	instruction2.setCharacterSize(20);
	instruction2.setFillColor(sf::Color::Green);
	auxRect = instruction2.getGlobalBounds();
	instruction2.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	instruction2.setPosition(sf::Vector2f(windowSize.x / 2, 250));

	instruction3.setFont(sampleFont2);
	instruction3.setString("You'll become a master of the air when you get a score of 300");
	instruction3.setCharacterSize(20);
	instruction3.setFillColor(sf::Color::Green);
	auxRect = instruction3.getGlobalBounds();
	instruction3.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	instruction3.setPosition(sf::Vector2f(windowSize.x / 2, 300));


	pressToContinuesText.setFont(sampleFont2);
	pressToContinuesText.setString("[C] to continue");
	pressToContinuesText.setCharacterSize(30);
	pressToContinuesText.setFillColor(sf::Color::Magenta);
	auxRect = pressToContinuesText.getGlobalBounds();
	pressToContinuesText.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	pressToContinuesText.setPosition(sf::Vector2f(windowSize.x / 2, 600));
}

Tutorial::~Tutorial()
{
}

void Tutorial::Update(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		game->SetGameState(GameState::MnMenu);
	}
}

void Tutorial::Draw(sf::RenderWindow* window)
{
	window->draw(title);
	window->draw(instruction1);
	window->draw(instruction2);
	window->draw(instruction3);
	window->draw(pressToContinuesText);
}
