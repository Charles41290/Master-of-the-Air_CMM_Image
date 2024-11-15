#pragma once
#include<iostream>
#include<list>
#include<vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObject.h"
#include "PlayerBullet.h"
#include "Bullet2.h"


class Player: public GameObject
{
	protected:
		int maxHealth = 200;
		int currentHealth;
		float speed = 400;
		float shootTimer = 0;
		float shootTime = 0.8f;
		std::string name;
		//std::vector<PlayerBullet*> bullets;
		std::vector<Bullet2*> bullets;
		sf::SoundBuffer shootBuffer;
		sf::Sound shootSound;
		sf::SoundBuffer dmgBuffer;
		sf::Sound dmgSound;
		sf::RectangleShape healthBar;
		sf::RectangleShape healthBarBg;
		
	public:
		int static score;
		Player();
		void Update(sf::Time deltaTime);
		void Draw(sf::RenderWindow* window);
		int GetHealth() { return this->currentHealth; };
		void OnCollisionEnter(GameObject* other) override;
		void OnCollisionStay(GameObject* other) override;
		void OnCollisionExit(GameObject* other) override;

};

