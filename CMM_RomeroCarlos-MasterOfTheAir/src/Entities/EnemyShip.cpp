#include <iostream>
#include "EnemyShip.h"
#include "CollisionsHandler.h"
#include "PlayerBullet.h"
#include "Bullet2.h"

#define PI 3.1415926

EnemyShip::EnemyShip(sf::Vector2f pos)
{
    currentHealth = maxHealth;
    initialY = pos.y;
    oscilationSpeed = GetOscilationSpeed();

    // Configuro el tipo a enemy
    type = "enemy";

    //Texturas
    texture.loadFromFile("res\\textures\\enemy_ship.png"); // ruta relativa al archivo vcxproj


    // geometría
    body = sf::RectangleShape(sf::Vector2f(124, 58));
    body.setOrigin(body.getSize().x/2, body.getSize().y/2);
    body.setPosition(sf::Vector2f(pos.x, pos.y)); 
    body.setTexture(&texture);

    // Sonido
    shootBuffer.loadFromFile("res\\sounds\\laserRetro1.ogg");
    shootSound.setBuffer(shootBuffer);
    shootSound.setVolume(50);
    dmgBuffer.loadFromFile("res\\sounds\\explosion2.ogg");
    dmgSound.setBuffer(dmgBuffer);

    //Barras de salud
    healthBarBg.setSize(sf::Vector2f(40, 5));
    healthBarBg.setFillColor(sf::Color::Red);
    healthBarBg.setPosition(sf::Vector2f(body.getPosition().x - 15, body.getPosition().y - body.getSize().y / 2 - 10));

    healthBar.setSize(sf::Vector2f(40, 5));
    healthBar.setFillColor(sf::Color::Green);
    healthBar.setPosition(sf::Vector2f(body.getPosition().x - 15, body.getPosition().y - body.getSize().y / 2 - 10));

    //Agregamos fisica
    physType = PhysicsType::Dynamic;
    CollisionsHandler::AddObject(this);
}

EnemyShip::~EnemyShip()
{
    for (Bullet2* bullet : bullets) {
        delete bullet; // Libera cada puntero.
    }
    bullets.clear();
}

float EnemyShip::GetOscilationSpeed()
{
	float initialOscilationSpeed = 5000.0f;
	std::srand(static_cast<unsigned int>(std::time(0)));
	// Genera un número aleatorio entre 1 y 6
	int numeroAleatorio = std::rand() % 6 + 1;
	return initialOscilationSpeed * numeroAleatorio;
    
}

float EnemyShip::PingPong(sf::Time deltaTime, float length)
{
    if (adding)
    {
        oscilator = deltaTime.asSeconds() * oscilationSpeed;
    }
    else
    {
        oscilator = -deltaTime.asSeconds() * oscilationSpeed;
    }

    if (oscilator >= length || oscilator <= length)
    {
        adding = !adding;
    }
    return oscilator;
}

void EnemyShip::Update(sf::Time deltaTime)
{
    if (currentHealth > 0)
    {
        //Movimiento
        oscilationTimer += deltaTime.asSeconds();
        if (oscilationTimer > oscilationTime)
        {
            body.setPosition(sf::Vector2f(body.getPosition().x, initialY + 50.0f * std::sin(2 * oscilationSpeed * PI * deltaTime.asSeconds())));
            healthBarBg.setPosition(sf::Vector2f(body.getPosition().x - 15, body.getPosition().y - body.getSize().y / 2 - 10));
            healthBar.setPosition(sf::Vector2f(body.getPosition().x - 15, body.getPosition().y - body.getSize().y / 2 - 10));
            oscilationTimer = 0;
        }

        // Lógica de disparo
        shootTimer += deltaTime.asSeconds();
        updateSpeedTimer += deltaTime.asSeconds();
        if(updateSpeedTimer > 3) // aumento la velocidad de disparo cada 3 segundos
        {
            bulletSpeed -= 50;
            updateSpeedTimer = 0;
        }
        if (shootTimer  > shootTime)
        {
            bullets.push_back(new Bullet2(body.getPosition(), sf::Vector2f(25, 12), bulletSpeed, "benemy"));
            shootSound.play();
            shootTimer = 0; // reinicio el timer de disparo
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            bullets[i]->Update(deltaTime);
        }
    }
}

void EnemyShip::Draw(sf::RenderWindow* window)
{
    if (currentHealth > 0)
    {
        window->draw(body);
        window->draw(healthBarBg);
        window->draw(healthBar);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            bullets[i]->Draw(window);
        }
    }
}

void EnemyShip::OnCollisionEnter(GameObject* other)
{
    if (currentHealth > 0 && other->GetType() == "bplayer")
    {
        currentHealth -= 10;
        dmgSound.play();
        Player::score += 10;
    }
    float healthPercentage = (float)currentHealth / (float)maxHealth;
    healthBar.setSize(sf::Vector2f(40 * healthPercentage, 5));
}

void EnemyShip::OnCollisionStay(GameObject* other)
{
}

void EnemyShip::OnCollisionExit(GameObject* other)
{
}
