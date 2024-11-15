#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Credits
{
    protected:
        sf::Text title;
        sf::Text author;
        sf::Text soundCredits;
        sf::Text fontCredits1;
        sf::Text fontCredits2;
        sf::Text musicCredit;
        sf::Text pressToContinuesText;
        sf::Font sampleFont;
        sf::Font sampleFont2;
        Game* game; // puntero a game

    public:
        Credits(sf::Vector2u windowSize, Game* game);
        void Update(sf::Time deltaTime);
        void Draw(sf::RenderWindow* window);

};

