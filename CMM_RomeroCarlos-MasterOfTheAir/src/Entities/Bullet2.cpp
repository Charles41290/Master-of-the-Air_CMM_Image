#include "Bullet2.h"
#include "CollisionsHandler.h"

Bullet2::Bullet2(sf::Vector2f position, sf::Vector2f size, float speed, std::string type): GameObject()
{
	//La bala se activa para que pueda dibujarse
	isActive = true;
	this->speed = speed;
	this->type = type;
	body = sf::RectangleShape(size);
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setPosition(position);


	pbullet.loadFromFile("res\\textures\\pmissil.png");
	ebullet.loadFromFile("res\\textures\\emissil.png");

	if(this->type == "bplayer")
	{
		body.setTexture(&pbullet);
	}
	else if(this->type == "benemy")
	{
		body.setTexture(&ebullet);
	}
	physType = PhysicsType::None; // importante! Si no, falla la validacion en CollisionHandler::SolveCollisions
	CollisionsHandler::AddObject(this);
}

void Bullet2::Update(sf::Time deltaTime)
{
	body.move(sf::Vector2f(speed * deltaTime.asSeconds(), 0));
}

void Bullet2::Draw(sf::RenderWindow* window)
{
	if (isActive)
	{
		window->draw(body);
	}
}

void Bullet2::OnCollisionEnter(GameObject* other)
{
	if(other->GetType() == "player" && this->type != "bplayer")
	{
		CollisionsHandler::RemoveObject(this); // quito la bala de collisionables
		this->isActive = false; // para evitar que una bala que haya impactado se vuelva a dibujar
	}

	if (other->GetType() == "enemy" && this->type != "benemy")
	{
		CollisionsHandler::RemoveObject(this);
		this->isActive = false; // para evitar que una bala que haya impactado se vuelva a dibujar
	}
}

void Bullet2::OnCollisionStay(GameObject* other)
{
}

void Bullet2::OnCollisionExit(GameObject* other)
{
}
