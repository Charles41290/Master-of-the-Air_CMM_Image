#pragma once
#include <SFML/Graphics.hpp>
#include "GamePlay.h"
#include "Escenas/MainMenu.h"
#include "Escenas/Credits.h"
#include "Escenas/Tutorial.h"

enum GameState
{
	None,
	MnMenu,
	Gameplay,
	Crdts,
	Tuto
};

class Game
{
public:
	//Atributos
	GameState gameState;
	sf::Clock clock;
	sf::RenderWindow* window;
	sf::Image icon;

	//Escenas
	MainMenu* mainMenu;
	GamePlay* gameplay;
	Credits* credits;
	Tutorial* tutorial;
	
	sf::Time deltaTime;

	Game();
	~Game();
	void SetGameState(GameState gs) { this->gameState = gs;}
	void Run();
	void Update();
	void Draw();
};

