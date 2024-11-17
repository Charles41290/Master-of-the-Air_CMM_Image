//include <SFML/Audio.hpp>
#include "Player.h"
#include "CollisionsHandler.h"
#include "Bullet2.h"

int Player::score = 0;

Player::Player()
{
	//Seteamos health
	currentHealth = maxHealth;

	// Configuro el tipo a player
	type = "player";

	//Texturas
	texture.loadFromFile("res\\textures\\ship3.png"); // ruta relativa al archivo vcxproj

	//Geometria
	body = sf::RectangleShape(sf::Vector2f(40,53));
	body.setOrigin(body.getSize().x/2, body.getSize().y/2); // el origen del cuerpo coincide con el baricentro 
	body.setPosition(sf::Vector2f(100, 460)); // medidos a partir de la esquina sup izquierda 
	body.setTexture(&texture);

	// Sonidos
	shootBuffer.loadFromFile("res\\sounds\\laserSmall.ogg");
	shootSound.setBuffer(shootBuffer);
	shootSound.setVolume(75);
	dmgBuffer.loadFromFile("res\\sounds\\explosion1.ogg");
	dmgSound.setBuffer(dmgBuffer);

	//Barras de salud
	healthBarBg.setSize(sf::Vector2f(40, 5));
	healthBarBg.setFillColor(sf::Color::Red);
	healthBarBg.setPosition(sf::Vector2f(body.getPosition().x-15, body.getPosition().y - body.getSize().y / 2 - 10));

	healthBar.setSize(sf::Vector2f(40, 5));
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setPosition(sf::Vector2f(body.getPosition().x - 15, body.getPosition().y - body.getSize().y / 2 - 10));
	
	//Agregamos fisica
	physType = PhysicsType::Dynamic;
	CollisionsHandler::AddObject(this);
}

Player::~Player()
{
	for (Bullet2* bullet : bullets) {
		delete bullet; // Libera cada puntero.
	}
	bullets.clear();

}

void Player::Update(sf::Time deltaTime)
{

	//Logica de disparo
	shootTimer += deltaTime.asSeconds(); //inicializo el timer de disparo
	float bulletSpeed = 500.0f;
	sf::Vector2f direction = sf::Vector2f(0, 0);

	if(shootTimer > shootTime)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bullets.push_back(new Bullet2(body.getPosition(),sf::Vector2f(12.5,6), bulletSpeed, "bplayer"));
			shootSound.play();
			shootTimer = 0; // reinicio el timer de disparo
		}
	}
	
	// Movimiento con AWSD
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction.y -= 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction.y += 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction.x -= 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction.x += 1;
	}

	float magnitude = sqrt(direction.x* direction.x+ direction.y* direction.y); // modulo del vector direction

	if (magnitude > 0) // > 0 implica cambio en el vector direccion
	{
		sf::Vector2f dirNormalized = direction / magnitude; // normalizo el vector direction
		body.move(dirNormalized * speed * deltaTime.asSeconds());
			healthBarBg.setPosition(sf::Vector2f(body.getPosition().x - 15, body.getPosition().y - body.getSize().y / 2 - 10));
			healthBar.setPosition(sf::Vector2f(body.getPosition().x - 15, body.getPosition().y - body.getSize().y / 2 - 10));
	}

	//Actualizo la posicion de las balas
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update(deltaTime);
	}
}

void Player::Draw(sf::RenderWindow* window)
{
	window->draw(body); // Dibujo el player
	window->draw(healthBarBg);
	window->draw(healthBar);
	for(size_t i = 0; i < bullets.size(); i++) // dibujo las balas del player
	{
		bullets[i]->Draw(window);
	}
}

void Player::OnCollisionEnter(GameObject* other)
{
	if (currentHealth >0 && other->GetType() == "benemy")
	{
		currentHealth -= 20;
		dmgSound.play();
		std::cout << "Player-Health: "<< currentHealth << std::endl;
	}
	float healthPercentage = (float)currentHealth / (float)maxHealth;
	healthBar.setSize(sf::Vector2f(40*healthPercentage,5));
}

void Player::OnCollisionStay(GameObject* other)
{
}

void Player::OnCollisionExit(GameObject* other)
{
}

