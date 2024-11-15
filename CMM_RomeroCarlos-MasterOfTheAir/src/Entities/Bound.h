#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "CollisionsHandler.h"
class Bound: public GameObject
{
	public:
		Bound(sf::Vector2f position, sf::Vector2f size);
		void Update(sf::Time deltaTime);
		void Draw(sf::RenderWindow* window);
		void OnCollisionEnter(GameObject* other) override;
		void OnCollisionStay(GameObject* other) override;
		void OnCollisionExit(GameObject* other) override;
};

