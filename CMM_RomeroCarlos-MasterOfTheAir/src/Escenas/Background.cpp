#include "Background.h"


Background::Background()
{
	/*texture.loadFromFile("res\\textures\\asteroid_bg.png");
	asteroid = sf::RectangleShape(sf::Vector2f(215,215));
	asteroid.setOrigin(asteroid.getSize().x / 2, asteroid.getSize().y / 2);
	asteroid.setPosition(sf::Vector2f(1200,700));
	asteroid.setTexture(&texture);*/

	texture2.loadFromFile("res\\textures\\planet03.png");
	planet = sf::RectangleShape(sf::Vector2f(640, 640));
	planet.setOrigin(planet.getSize().x / 2, planet.getSize().y / 2);
	planet.setPosition(sf::Vector2f(1200, 700));
	planet.setTexture(&texture2);

	texture3.loadFromFile("res\\textures\\nebula.png");
	bg = sf::RectangleShape(sf::Vector2f(1280, 760));
	//bg.setOrigin(planet.getSize().x / 2, planet.getSize().y / 2);
	bg.setPosition(sf::Vector2f(0, 0));
	bg.setTexture(&texture3);
	sf::Color color = bg.getFillColor();
	color.a = 128;
	bg.setFillColor(color);

}

void Background::Update(sf::Time deltaTime)
{
	planet.rotate(10*deltaTime.asSeconds());

}

void Background::Draw(sf::RenderWindow* window)
{
	window->draw(bg);
	//window->draw(asteroid);
	window->draw(planet);
}

void Background::OnCollisionEnter(GameObject* other)
{
}

void Background::OnCollisionStay(GameObject* other)
{
}

void Background::OnCollisionExit(GameObject* other)
{
}
