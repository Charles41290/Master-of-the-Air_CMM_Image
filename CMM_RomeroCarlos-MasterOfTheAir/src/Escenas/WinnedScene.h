#pragma once
#include <SFML/Graphics.hpp>
class WinnedScene
{
	protected:
		sf::Text winnedText;
		sf::Text pressToContinueText;
		sf::Font sampleFont;

	public:
		WinnedScene(sf::Vector2u windowSize);
		~WinnedScene();
		void Update(sf::Time deltaTime);
		void Draw(sf::RenderWindow* window);
};

