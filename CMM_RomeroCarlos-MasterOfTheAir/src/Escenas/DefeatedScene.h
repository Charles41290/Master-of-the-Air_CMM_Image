#pragma once
#include <SFML/Graphics.hpp>

//class GamePlay;

class Game;

class DefeatedScene
{
	protected:
		sf::Text defeatedText;
		sf::Text pressToContinueText;
		sf::Font sampleFont;

		Game* game;

	public:
		DefeatedScene(sf::Vector2u windowSize, Game* game);
		void Update(sf::Time deltaTime);
		void Draw(sf::RenderWindow* window);
		
};

