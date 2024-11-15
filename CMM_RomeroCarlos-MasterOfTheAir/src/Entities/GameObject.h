#pragma once

#include <vector>
#include <list>
#include <utility>  // Para std::pair
#include <SFML/Graphics.hpp>

//enum class PhysicsType {
//	None,
//	Static,
//	Dynamic
//};

class GameObject
{
	protected:
		enum PhysicsType {
			None,
			Static,
			Dynamic
		};
		sf::Texture texture;
		std::string type = "";
		sf::Sprite sprite;
		sf::RectangleShape body;
		//PhysicsType physType;
		bool physicsOn;


	public:
		//Atributos
		PhysicsType physType;
		sf::Sprite GetSprite() { return sprite; }
		sf::RectangleShape GetBody() { return body; }
		sf::Vector2f GetCenteredPosition();

		

		//Constructor
		GameObject();
		
		// Métodos
		bool isPhysicsOn();
		bool isColliding(GameObject* other);
		void ApplyPhysics(sf::Vector2f correction);
		std::string GetType() { return type; }
		PhysicsType GetPhysType() { return physType; }
		virtual void OnCollisionEnter(GameObject* other) = 0;
		virtual void OnCollisionStay(GameObject* other) = 0;
		virtual void OnCollisionExit(GameObject* other) = 0;

};

