#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "Bullet2.h"
#include <SFML/Graphics.hpp>

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
        bool adding = true;
        std::vector<Bullet2*> bullets;
        sf::RectangleShape healthBar;
        sf::RectangleShape healthBarBg;

    public:
        EnemyShip(sf::Vector2f pos);
        int GetHealth() { return this->currentHealth; }
        float GetOscilationSpeed();
        float PingPong(sf::Time deltaTime, float length);
        void Update(sf::Time deltaTime);
        void Draw(sf::RenderWindow* window);
        void OnCollisionEnter(GameObject* other) override;
        void OnCollisionStay(GameObject* other) override;
        void OnCollisionExit(GameObject* other) override;

};

