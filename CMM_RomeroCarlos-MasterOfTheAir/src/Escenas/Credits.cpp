#include "Credits.h"
#include "../Game.h"

Credits::Credits(sf::Vector2u windowSize, Game* game): game(game)
{
	sampleFont.loadFromFile("res\\fonts\\MigaeSemibold.otf");
	title.setFont(sampleFont);
	title.setString("Credits");
	title.setCharacterSize(50);       // Tamaño del texto en píxeles
	title.setFillColor(sf::Color::Yellow); // Color del texto
	sf::FloatRect auxRect = title.getGlobalBounds();// utilizo un auxRect para centrar el título
	title.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	title.setPosition(sf::Vector2f(windowSize.x / 2, 100));      // Posición en la ventana

	// Author
	sampleFont2.loadFromFile("res\\fonts\\SourGummy-Light.ttf");
	author.setFont(sampleFont2);
	author.setString("Author: Carlos Romero - 2024");
	author.setCharacterSize(20);
	author.setFillColor(sf::Color::Green);
	auxRect = author.getGlobalBounds();
	author.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	author.setPosition(sf::Vector2f(windowSize.x / 2, 200));

	// Fuentes
	sampleFont2.loadFromFile("res\\fonts\\SourGummy-Light.ttf");
	fontCredits1.setFont(sampleFont2);
	fontCredits1.setString("Fonts:         MigaeSemibold-Jolicia Type Foundry-License: Demo");
	fontCredits1.setCharacterSize(20);
	fontCredits1.setFillColor(sf::Color::Green);
	auxRect = fontCredits1.getGlobalBounds();
	fontCredits1.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	fontCredits1.setPosition(sf::Vector2f(windowSize.x / 2, 250));

	fontCredits2.setFont(sampleFont2);
	fontCredits2.setString("SourGummy Light-Google Fonts");
	fontCredits2.setCharacterSize(20);
	fontCredits2.setFillColor(sf::Color::Green);
	auxRect = fontCredits2.getGlobalBounds();
	fontCredits2.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	fontCredits2.setPosition(sf::Vector2f(windowSize.x / 2, 300));

	//Sprites y Sound Effects
	soundCredits.setFont(sampleFont2);
	soundCredits.setString("Sprite and Sound Effects: KENNY - License: CCO");
	soundCredits.setCharacterSize(20);
	soundCredits.setFillColor(sf::Color::Green);
	auxRect = soundCredits.getGlobalBounds();
	soundCredits.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	soundCredits.setPosition(sf::Vector2f(windowSize.x / 2, 350));

	//Musica
	musicCredit.setFont(sampleFont2);
	musicCredit.setString("Music: 2 beats per second-Roald Strauss - License: CCO");
	musicCredit.setCharacterSize(20);
	musicCredit.setFillColor(sf::Color::Green);
	auxRect = musicCredit.getGlobalBounds();
	musicCredit.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	musicCredit.setPosition(sf::Vector2f(windowSize.x / 2, 400));

	 pressToContinuesText.setFont(sampleFont2);
	 pressToContinuesText.setString("[C] to continue");
	 pressToContinuesText.setCharacterSize(30);
	 pressToContinuesText.setFillColor(sf::Color::Magenta);
	auxRect =  pressToContinuesText.getGlobalBounds();
	 pressToContinuesText.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	 pressToContinuesText.setPosition(sf::Vector2f(windowSize.x / 2, 600));

}

Credits::~Credits()
{
}

void Credits::Update(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		game->SetGameState(GameState::MnMenu);
	}
}

void Credits::Draw(sf::RenderWindow* window)
{
	window->draw(title);
	window->draw(author);
	window->draw(fontCredits1);
	window->draw(fontCredits2);
	window->draw(soundCredits);
	window->draw(musicCredit);
	window->draw(pressToContinuesText);

}	

