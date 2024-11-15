#include "MainMenu.h"
#include "../Game.h" // Al incluir el Game.h se genera una referencia circular -> esto se evita incluyendo Game.h en MainMenu.cpp ya que los .h y los .cpp se compilan de forma independiente


//MainMenu::MainMenu(sf::Vector2u windowSize)
MainMenu::MainMenu(sf::Vector2u windowSize, Game* game): game(game) // incializo el atributo game de la clase MainMenu -> primer game es el nombre del atributo, segundo game es el arg que le paso en el constructor
{
	//Textura del boton
	bttn_texture.loadFromFile("res\\textures\\Button.png");
	option = sf::RectangleShape(sf::Vector2f(170, 87));
	option.setFillColor(sf::Color::Blue);
	for (int i = 0; i < 4; i++)
	{
		option.setOrigin(option.getSize().x / 2, option.getSize().y / 2);
		option.setPosition(sf::Vector2f(windowSize.x/2,250+i*100));
		option.setTexture(&bttn_texture);
		menuOptions.push_back(option);
	}

	//Texto
	//Titulo
	sampleFont.loadFromFile("res\\fonts\\MigaeSemibold.otf");
	title.setFont(sampleFont);
	title.setString("Master of the Air");
	title.setCharacterSize(50);       // Tamaño del texto en píxeles
	title.setFillColor(sf::Color::Yellow); // Color del texto
	sf::FloatRect auxRect = title.getGlobalBounds();// utilizo un auxRect para centrar el título
	title.setOrigin(sf::Vector2f(auxRect.width/2, auxRect.height/2));
	title.setPosition(sf::Vector2f(windowSize.x / 2, 100));      // Posición en la ventana

	// StartGame
	sampleFont2.loadFromFile("res\\fonts\\SourGummy-Light.ttf");
	startOption.setFont(sampleFont2);
	startOption.setString("Play [Enter]");
	startOption.setCharacterSize(23);
	startOption.setFillColor(sf::Color::Green);
	auxRect = startOption.getGlobalBounds();
	startOption.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	startOption.setPosition(sf::Vector2f(windowSize.x / 2, menuOptions[0].getPosition().y-5));

	// Tutorial
	tutorialOption.setFont(sampleFont2);
	tutorialOption.setString("Tutorial [T]");
	tutorialOption.setCharacterSize(23);
	tutorialOption.setFillColor(sf::Color::Green);
	auxRect = tutorialOption.getGlobalBounds();
	tutorialOption.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	tutorialOption.setPosition(sf::Vector2f(windowSize.x / 2, menuOptions[1].getPosition().y - 5));

	//Creditos
	creditsOption.setFont(sampleFont2);
	creditsOption.setString("Credits [R]");
	creditsOption.setCharacterSize(23);
	creditsOption.setFillColor(sf::Color::Green);
	auxRect = creditsOption.getGlobalBounds();
	creditsOption.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	creditsOption.setPosition(sf::Vector2f(windowSize.x / 2, menuOptions[2].getPosition().y - 5));

	//Salida
	exitOption.setFont(sampleFont2);
	exitOption.setString("Exit [ESC]");
	exitOption.setCharacterSize(23);
	exitOption.setFillColor(sf::Color::Green);
	auxRect = exitOption.getGlobalBounds();
	exitOption.setOrigin(sf::Vector2f(auxRect.width / 2, auxRect.height / 2));
	exitOption.setPosition(sf::Vector2f(windowSize.x / 2, menuOptions[3].getPosition().y - 5));


}

void MainMenu::Update(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		game->SetGameState(GameState::Gameplay);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		game->SetGameState(GameState::Crdts);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		game->SetGameState(GameState::Tuto);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game->SetGameState(GameState::None);
	}

}

void MainMenu::Draw(sf::RenderWindow* window)
{
	for (int i = 0; i < 4; i++)
	{
		window->draw(menuOptions[i]);
	}
	window->draw(title);
	window->draw(startOption);
	window->draw(tutorialOption);
	window->draw(creditsOption);
	window->draw(exitOption);

	

}
