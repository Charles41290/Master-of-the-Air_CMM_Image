#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "Bullet2.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class EnemyShip : GameObject
{
    protected:
	    int maxHealth = 100;
	    int currentHealth;
        float initialY;
        float oscilator;
        float oscilationLength = 50.0f;
        float oscilationTime = 1.0f;
        float oscilationTimer = 0.0f;
        float oscilationSpeed;
        float shootTimer = 0.0f;
        float shootTime = 1.0f;
        float bulletSpeed = -400.0;
        float updateSpeedTimer = 0.0;
        bool adding = true;
        std::vector<Bullet2*> bullets;
        sf::SoundBuffer shootBuffer;
        sf::Sound shootSound;
        sf::SoundBuffer dmgBuffer;
        sf::Sound dmgSound;
        sf::RectangleShape healthBar;
        sf::RectangleShape healthBarBg;

    public:
        EnemyShip(sf::Vector2f pos);
        ~EnemyShip();
        int GetHealth() { return this->currentHealth; }
        float GetOscilationSpeed();
        float PingPong(sf::Time deltaTime, float length);
        void Update(sf::Time deltaTime);
        void Draw(sf::RenderWindow* window);
        void OnCollisionEnter(GameObject* other) override;
        void OnCollisionStay(GameObject* other) override;
        void OnCollisionExit(GameObject* other) override;

};

