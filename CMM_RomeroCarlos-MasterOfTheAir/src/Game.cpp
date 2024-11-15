#include "Game.h"
#include<iostream>
#include <SFML/Graphics.hpp>

Game::Game()
{
	// Valor inicial para que el juego empiece en el menú principal
	gameState = GameState::MnMenu;

	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Master of the Air");
	icon.loadFromFile("res\\spitfire.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	clock = sf::Clock();
	deltaTime = sf::Time(); // tiempo entre frames

	// Instanciacion de escenas
	mainMenu = new MainMenu(window->getSize(), this);
	credits = new Credits(window->getSize(), this);
	tutorial = new Tutorial(window->getSize(), this);
	gameplay = new GamePlay(window->getSize(), this);

}

void Game::Run()
{
	while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
		Update();
		Draw();
    }
	
}

void Game::Update()
{
	deltaTime = clock.restart();

	/*std::cout << "Running";*/
	//std::cout << (int)gameState;
	switch (gameState)
	{
	case None:
		window->close();
		break;
	case MnMenu:
		//std::cout << "Dentro de main menu";
		mainMenu->Update(deltaTime);
		break;
	case Gameplay:
		gameplay->Update(deltaTime);
		break;
	case Crdts:
		credits->Update(deltaTime);
		break;
	case Tuto:
		tutorial->Update(deltaTime);
		break;
	default:
		std::cout << "Default option";
		break;
	}

	//gameplay->Update(deltaTime);
	
}

void Game::Draw()
{
	window->clear();

	switch (gameState)
	{
	case None:
		window->close();
		break;
	case MnMenu:
		mainMenu->Draw(window);
		break;
	case Gameplay:
		gameplay->Draw(window);
		break;
	case Crdts:
		credits->Draw(window);
		break;
	case Tuto:
		tutorial->Draw(window);
		break;
	default:
		std::cout << "Default option";
		break;
	}

	//gameplay->Draw(window);

	window->display();
}
