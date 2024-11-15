#include "GameObject.h"
#include <iostream>


GameObject::GameObject()
{

}


sf::Vector2f GameObject::GetCenteredPosition()
{
	sf::FloatRect auxRect = body.getGlobalBounds();
	sf::Vector2f pos(body.getPosition().x + auxRect.getSize().x/2, body.getPosition().y + auxRect.getSize().y / 2);
	return pos;
}

bool GameObject::isPhysicsOn()
{
	return physicsOn;
}

bool GameObject::isColliding(GameObject* other)
{
	sf::FloatRect thisBounds = body.getGlobalBounds();
	sf::FloatRect otherBounds = other->body.getGlobalBounds();
	// Debug
	/*std::cout << "Este objeto (Cuerpo): " << thisBounds.left << ", " << thisBounds.top
		<< ", " << thisBounds.width << ", " << thisBounds.height << std::endl;
	std::cout << "Otro objeto (Cuerpo): " << otherBounds.left << ", " << otherBounds.top
		<< ", " << otherBounds.width << ", " << otherBounds.height << std::endl;*/


	return thisBounds.intersects(otherBounds);
}

void GameObject::ApplyPhysics(sf::Vector2f correction)
{
	body.move(correction);
}



