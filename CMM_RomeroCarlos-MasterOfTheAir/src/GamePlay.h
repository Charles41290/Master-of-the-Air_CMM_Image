#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include "Entities/Bullet2.h"
#include "Entities/EnemyShip.h"
#include "Entities/Bound.h"
#include "Entities/PlayerBullet.h"
#include "Escenas/Background.h"
#include "Escenas/DefeatedScene.h"
#include "Escenas/WinnedScene.h"
#include "Escenas/Score.h"

enum GameplayState
{
	defeated,
	playing,
	winnned
};

class Game;

class GamePlay
{
	protected:
		int screenWidth = 1280; //unsigned int 
		int screenHeight = 720;
		float boundThickness = 20;
		GameplayState gamePlayState;
		Player* player;
		EnemyShip* enemyShip;
		EnemyShip* enemyShip2;
		EnemyShip* enemyShip3;
		Bound* upperBound;
		Bound* leftBound;
		Bound* rightBound;
		Background background;
		Game* game;
		//Escenas - Defeated y Winned
		DefeatedScene* defeatedScene; // es necesario inicializarla en la lista de Incialización del  constructor 
		WinnedScene* winnedScene;


	public:
		GamePlay(sf::Vector2u windowSize,Game* game);
		~GamePlay();
		void Update(sf::Time deltaTime);
		void Draw(sf::RenderWindow* window);
		void ResetGame();

};

