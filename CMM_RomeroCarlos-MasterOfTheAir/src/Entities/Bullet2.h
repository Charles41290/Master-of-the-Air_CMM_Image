#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Bullet2: public GameObject
{
	protected:
		float speed;
		bool isActive;
		sf::Texture ebullet;
		sf::Texture pbullet;


	public:
		Bullet2(sf::Vector2f position, sf::Vector2f size, float speed, std::string type);
		void Update(sf::Time deltaTime);
		void Draw(sf::RenderWindow* window);

		void OnCollisionEnter(GameObject* other) override;
		void OnCollisionStay(GameObject* other) override;
		void OnCollisionExit(GameObject* other) override;
};

