#include "PlayerBullet.h"
#include "CollisionsHandler.h"


PlayerBullet::PlayerBullet(sf::Vector2f position, float speed):Bullet(position, sf::Vector2f(10,10), speed)
{
	////isActive = true;
	////size = sf::Vector2f(10, 10);
	//body = sf::RectangleShape(sf::Vector2f(20.f, 20.f));
	////body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	//body.setPosition(position);
	//body.setFillColor(sf::Color::Blue);
	//this->speed = speed;

	//std::cout << "Tamaño global de la bala: " << body.getGlobalBounds().width << ", "<< body.getGlobalBounds().height << std::endl;

	//physType = PhysicsType::Dynamic;
	CollisionsHandler::AddObject(this);
}

void PlayerBullet::Update(sf::Time deltaTime)
{
	//body.setPosition(sf::Vector2f(body.getPosition().x + speed*deltaTime.asSeconds(), body.getPosition().y));
	body.move(sf::Vector2f(speed * deltaTime.asSeconds(), 0));
}

void PlayerBullet::Draw(sf::RenderWindow* window)
{
	if (isActive) 
	{
		window->draw(body);
	}
}

void PlayerBullet::OnCollisionEnter(GameObject* other)
{
	std::cout << "Impacto desde bala" << std::endl;
}

void PlayerBullet::OnCollisionStay(GameObject* other)
{
}

void PlayerBullet::OnCollisionExit(GameObject* other)
{
}


