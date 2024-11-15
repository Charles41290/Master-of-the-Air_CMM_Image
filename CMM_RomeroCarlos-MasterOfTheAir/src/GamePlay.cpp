#include "GamePlay.h"
#include "Entities/Bound.h"
#include "Escenas/Background.h"
#include "Entities/CollisionsHandler.h"
#include "Game.h"
#include<iostream>
#include <SFML/Graphics.hpp>


GamePlay::GamePlay(sf::Vector2u windowSize, Game* game) : game(game)
{
	gamePlayState = GameplayState::playing;
	Background background();
	player = new Player();
	enemyShip = new EnemyShip(sf::Vector2f(screenWidth - 100, screenHeight / 4));

	//Bounds
	upperBound = new Bound(sf::Vector2f(0, 0), sf::Vector2f(1280, 93));

	//Escenas
	defeatedScene = new DefeatedScene(windowSize, game);

}

void GamePlay::Update(sf::Time deltaTime)
{
	if(player->GetHealth() <= 0)
	{
		gamePlayState = GameplayState::defeated;
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
			CollisionsHandler::Update();
			break;

		case defeated:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				game->SetGameState(GameState::MnMenu);
				gamePlayState = GameplayState::playing;
				ResetGame();
				
			}
			//std::cout << "Defeated" << std::endl;
			break;

	}

	//background.Update(deltaTime);
	//player->Update(deltaTime);
	//enemyShip->Update(deltaTime);
	////bullet->Update(deltaTime);
	////upperBound->GetBody().rotate(1.0f*deltaTime.asSeconds());
	//CollisionsHandler::Update();
	
}

void GamePlay::Draw(sf::RenderWindow* window)
{

	switch (gamePlayState)
	{
	case playing:
		upperBound->Draw(window);
		background.Draw(window);
		player->Draw(window);
		enemyShip->Draw(window);
		break;

	case defeated:
		defeatedScene->Draw(window);
		std::cout << "Defeated" << std::endl;
		break;

	case winnned:

		break;

	}
	/*upperBound->Draw(window);
	background.Draw(window);
	player->Draw(window);
	enemyShip->Draw(window);*/
	//bullet->Draw(window);

	//bullet->Draw(window);
	
	//upperBound2->Draw(window);
	//upperBound3->Draw(window);
	
}

void GamePlay::ResetGame()
{
	CollisionsHandler::Reset();
	player = new Player();
	enemyShip = new EnemyShip(sf::Vector2f(screenWidth - 100, screenHeight / 4));

	//Bounds
	upperBound = new Bound(sf::Vector2f(0, 0), sf::Vector2f(1280, 93));
}
