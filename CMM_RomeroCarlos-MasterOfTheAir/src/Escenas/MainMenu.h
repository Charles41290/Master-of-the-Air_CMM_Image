#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Game; // declaración adelantada para evitar referencias circulares

class MainMenu
{
	protected:
		sf::Text title;
		sf::Text startOption;
		sf::Text tutorialOption;
		sf::Text creditsOption;
		sf::Text exitOption;
		sf::Font sampleFont;
		sf::Font sampleFont2;
		sf::Texture bttn_texture;
		sf::RectangleShape option;
		std::vector<sf::RectangleShape> menuOptions;

		Game* game; // puntero a game -> lo necesito para modificar GameState
		
	public:
		//MainMenu(sf::Vector2u windowSize);
		MainMenu(sf::Vector2u windowSize, Game* game);
		//MainMenu(sf::Vector2u windowSize);
		void Update(sf::Time deltaTime);
		void Draw(sf::RenderWindow* window);
};

