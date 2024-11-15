#include "Bound.h"


Bound::Bound(sf::Vector2f position, sf::Vector2f size, bool soundOn, bool textureOn)
{
	if (textureOn)
	{
		//Texturas
		texture.loadFromFile("res\\textures\\asteroids4.png"); // ruta relativa al archivo vcxproj
		texture.setRepeated(true);

		// geometria
		body = sf::RectangleShape(size);
		body.setPosition(position);
		body.setTexture(&texture);
		body.setTextureRect(sf::IntRect(0, 0, 1280, 93)); // me aseguro que
	}
	else
	{
		body = sf::RectangleShape(size);
		body.setPosition(position);
		body.setFillColor(sf::Color(0,0,0,0));
	}

	// fisica
	physType = PhysicsType::Static;
	CollisionsHandler::AddObject(this);

}

void Bound::Update(sf::Time deltaTime)
{
}

void Bound::Draw(sf::RenderWindow* window)
{
	window->draw(body);
}

void Bound::OnCollisionEnter(GameObject* other)
{
}

void Bound::OnCollisionStay(GameObject* other)
{
}

void Bound::OnCollisionExit(GameObject* other)
{
}
