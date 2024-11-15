#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "CollisionsHandler.h"

class Bullet: public GameObject
{
	protected:
		sf::Vector2f size;
		sf::RectangleShape body;
		float speed;
		bool isActive;

	public:
		Bullet(sf::Vector2f position, sf::Vector2f size, float speed);
		virtual void Update(sf::Time deltaTime) = 0;
		virtual void Draw(sf::RenderWindow* window) = 0;
		void OnCollisionEnter(GameObject* other) override;
		void OnCollisionStay(GameObject* other) override;
		void OnCollisionExit(GameObject* other) override;


};

