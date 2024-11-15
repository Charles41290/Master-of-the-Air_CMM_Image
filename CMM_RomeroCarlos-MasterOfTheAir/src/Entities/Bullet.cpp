#include "Bullet.h"
//#include "CollisionsHandler.h"
//
//Bullet::Bullet(sf::Vector2f position, float speed)
//{
//	isActive = true;
//	size = sf::Vector2f(10, 10);
//	body = sf::RectangleShape(size);
//	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
//	body.setPosition(position);
//	body.setFillColor(sf::Color::Blue);
//	this->speed = speed;
//
//	//Agregamos fisica
//	//physType = PhysicsType::Dynamic;
//	CollisionsHandler::AddObject(this);
//
//}
//
//void Bullet::Update(sf::Time deltaTime)
//{
//	body.setPosition(sf::Vector2f(body.getPosition().x + speed * deltaTime.asSeconds(), body.getPosition().y));
//}
//
//void Bullet::Draw(sf::RenderWindow* window)
//{
//	if (isActive)
//	{
//		window->draw(body);
//	}
//}
//
//void Bullet::OnCollisionEnter(GameObject* other)
//{
//	std::cout << "Colisionando" << std::endl;
//}
//
//void Bullet::OnCollisionStay(GameObject* other)
//{
//}
//
//void Bullet::OnCollisionExit(GameObject* other)
//{
//}

Bullet::Bullet(sf::Vector2f position, sf::Vector2f size, float speed)
{
	this->size = size;
	body = sf::RectangleShape(size);
	body.setOrigin(body.getSize().x/2, body.getSize().y / 2);
	body.setPosition(position);
	body.setFillColor(sf::Color::Blue);

	this->speed = speed;
	isActive = true;

	physType = PhysicsType::Dynamic;

}

void Bullet::OnCollisionEnter(GameObject* other)
{
}

void Bullet::OnCollisionStay(GameObject* other)
{
}

void Bullet::OnCollisionExit(GameObject* other)
{
}
