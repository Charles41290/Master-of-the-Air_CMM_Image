#pragma once
#include<iostream>
#include "Bullet.h"


class PlayerBullet : public Bullet
{
	public:
		PlayerBullet(sf::Vector2f position, float speed);
		void Update(sf::Time deltaTime) override;
		void Draw(sf::RenderWindow* window) override;
		void OnCollisionEnter(GameObject* other) override;
		void OnCollisionStay(GameObject* other) override;
		void OnCollisionExit(GameObject* other) override;
		
};

