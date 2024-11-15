#pragma once
#include "../Entities/GameObject.h"
#include <SFML/Graphics.hpp>
class Background : public GameObject
{
	protected:
		sf::Texture texture2;
		sf::Texture texture3;
		sf::RectangleShape asteroid;
		sf::RectangleShape planet;
		sf::RectangleShape bg;

	public:
		Background();
		void Update(sf::Time deltaTime);
		void Draw(sf::RenderWindow* window);
		void OnCollisionEnter(GameObject* other) override;
		void OnCollisionStay(GameObject* other) override;
		void OnCollisionExit(GameObject* other) override;


};

