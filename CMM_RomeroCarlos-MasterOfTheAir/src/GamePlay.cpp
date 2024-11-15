#include "GamePlay.h"
#include "Entities/Bound.h"
#include "Escenas/Background.h"
#include "Entities/CollisionsHandler.h"
#include "Game.h"
#include<iostream>
#include <SFML/Graphics.hpp>


GamePlay::GamePlay(sf::Vector2u windowSize, Game* game) : game(game), background() // inicializo game y background en la lista de inicializacion
{
	gamePlayState = GameplayState::playing;
	//Background background();
	player = new Player();
	enemyShip = new EnemyShip(sf::Vector2f(screenWidth - 100, screenHeight / 4));
	enemyShip2 = new EnemyShip(sf::Vector2f(screenWidth - 100, screenHeight / 2));
	enemyShip3 = new EnemyShip(sf::Vector2f(screenWidth - 100, 3* screenHeight / 4));

	//Bounds
	upperBound = new Bound(sf::Vector2f(0, 0), sf::Vector2f(1280, 93), true, true);
	leftBound = new Bound(sf::Vector2f(0, 0), sf::Vector2f(20, 720), false, false);
	rightBound = new Bound(sf::Vector2f(1260, 0), sf::Vector2f(20, 720), false, false);


	//Escenas
	defeatedScene = new DefeatedScene(windowSize, game);
	winnedScene = new WinnedScene(windowSize);

}

void GamePlay::Update(sf::Time deltaTime)
{
	if(player->GetHealth() <= 0)
	{
		gamePlayState = GameplayState::defeated;
	}

	if (Player::score == 100)
	{
		gamePlayState = GameplayState::winnned;
	}

	switch(gamePlayState)
	{
		case playing:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				game->SetGameState(GameState::MnMenu);
			}
			background.Update(deltaTime);
			player->Update(deltaTime);
			enemyShip->Update(deltaTime);
			enemyShip2->Update(deltaTime);
			enemyShip3->Update(deltaTime);
			CollisionsHandler::Update();
			break;

		case defeated:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				game->SetGameState(GameState::MnMenu);
				gamePlayState = GameplayState::playing;
				ResetGame();
				
			}
			break;
		case winnned:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				game->SetGameState(GameState::MnMenu);
				gamePlayState = GameplayState::playing;
				ResetGame();
			}
			break;
	}
}

void GamePlay::Draw(sf::RenderWindow* window)
{

	switch (gamePlayState)
	{
	case playing:
		upperBound->Draw(window);
		leftBound->Draw(window);
		rightBound->Draw(window);
		background.Draw(window);
		player->Draw(window);
		enemyShip->Draw(window);
		enemyShip2->Draw(window);
		enemyShip3->Draw(window);
		break;

	case defeated:
		defeatedScene->Draw(window);
		break;

	case winnned:
		winnedScene->Draw(window);
		break;
	}
}

void GamePlay::ResetGame()
{
	std::cout << "En Reset Game" << std::endl;
	CollisionsHandler::Reset();
	player = new Player();
	Player::score = 0;
	enemyShip = new EnemyShip(sf::Vector2f(screenWidth - 100, screenHeight / 4));
	enemyShip2 = new EnemyShip(sf::Vector2f(screenWidth - 100, screenHeight / 2));
	enemyShip3 = new EnemyShip(sf::Vector2f(screenWidth - 100, 3 * screenHeight / 4));
	//Bounds
	upperBound = new Bound(sf::Vector2f(0, 0), sf::Vector2f(1280, 93), true, true);
	leftBound = new Bound(sf::Vector2f(0, 0), sf::Vector2f(1280, 93), false, false);
}
