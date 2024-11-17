#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Tutorial
{
    protected:
        sf::Text title;
        sf::Text instruction1;
        sf::Text instruction2;
        sf::Text instruction3;
        sf::Text pressToContinuesText;
        sf::Font sampleFont;
        sf::Font sampleFont2;

        Game* game;

    public:
        Tutorial(sf::Vector2u windowSize, Game* game);
        ~Tutorial();
        void Update(sf::Time deltaTime);
        void Draw(sf::RenderWindow* window);

};

