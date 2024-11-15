#include "CollisionsHandler.h"
#include <algorithm> // Para std::find

// Inicialización de los atributos estáticos
std::vector<GameObject*> CollisionsHandler::collisionables;
std::list<std::pair<GameObject*, GameObject*>> CollisionsHandler::collisionRegistry;

void CollisionsHandler::AddObject(GameObject* obj) {
    auto it = std::find(collisionables.begin(), collisionables.end(), obj);
    if (it == collisionables.end()) {
        collisionables.push_back(obj);
        // std::cout << "Objeto agregado a collisionables: " << obj->GetBody().getGlobalBounds().height << "-" << obj->GetBody().getGlobalBounds().width << std::endl; //Debug
    }
}

void CollisionsHandler::RemoveObject(GameObject* obj) {
    auto it = std::find(collisionables.begin(), collisionables.end(), obj);
    if (it != collisionables.end()) {
        collisionables.erase(it);
    }
}

void CollisionsHandler::Reset() {
    collisionables.clear();
    collisionRegistry.clear();
}

void CollisionsHandler::SolvePhysics(GameObject* first, GameObject* second) {
    sf::FloatRect firstBounds = first->GetBody().getGlobalBounds();
    sf::FloatRect secondBounds = second->GetBody().getGlobalBounds();

    sf::Vector2f firstPos(firstBounds.left + firstBounds.width / 2.f, firstBounds.top + firstBounds.height / 2.f);
    sf::Vector2f secondPos(secondBounds.left + secondBounds.width / 2.f, secondBounds.top + secondBounds.height / 2.f);

    float minHorDistance = firstBounds.width / 2.f + secondBounds.width / 2.f;
    float minVerDistance = firstBounds.height / 2.f + secondBounds.height / 2.f;

    sf::Vector2f diff = firstPos - secondPos;

    float horPenetration = minHorDistance - std::abs(diff.x);
    float verPenetration = minVerDistance - std::abs(diff.y);

    sf::Vector2f firstSeparation, secondSeparation;
    float firstDisplacement, secondDisplacement;
    float firstDisplacementSign, secondDisplacementSign;
    bool isPositiveDiff;

    if (horPenetration > verPenetration) {
        isPositiveDiff = (diff.y > 0.f);
        firstDisplacementSign = (isPositiveDiff) ? 1.f : -1.f;
        secondDisplacementSign = (!isPositiveDiff) ? 1.f : -1.f;

        firstDisplacement = verPenetration * 0.5f * firstDisplacementSign;
        secondDisplacement = verPenetration * 0.5f * secondDisplacementSign;

        firstSeparation = sf::Vector2f(0.f, firstDisplacement);
        secondSeparation = sf::Vector2f(0.f, secondDisplacement);
    }
    else {
        isPositiveDiff = (diff.x > 0.f);
        firstDisplacementSign = (isPositiveDiff) ? 1.f : -1.f;
        secondDisplacementSign = (!isPositiveDiff) ? 1.f : -1.f;

        firstDisplacement = horPenetration * 0.5f * firstDisplacementSign;
        secondDisplacement = horPenetration * 0.5f * secondDisplacementSign;

        firstSeparation = sf::Vector2f(firstDisplacement, 0.f);
        secondSeparation = sf::Vector2f(secondDisplacement, 0.f);
    }

    // opcion alterna usando enum class en GameObject
    /*if (static_cast<int>(first->GetPhysType()) == CollisionsHandler::PhysicsType::Dynamic) {
        first->ApplyPhysics(firstSeparation);
    }*/

    if (first->GetPhysType() == CollisionsHandler::PhysicsType::Dynamic) {
        first->ApplyPhysics(firstSeparation);
    }
    if (second->GetPhysType() == CollisionsHandler::PhysicsType::Dynamic) {
        second->ApplyPhysics(secondSeparation);
    }
}

void CollisionsHandler::SolveCollisions(GameObject* first, GameObject* second) {
    if (first->GetPhysType() != CollisionsHandler::PhysicsType::None && second->GetPhysType() != CollisionsHandler::PhysicsType::None) {
        SolvePhysics(first, second);
    }
}

void CollisionsHandler::Update() {
    //std::cout << "Size de collisionables " << collisionables.size() << std::endl;  // Debug
    for (size_t i = 0; i < collisionables.size(); i++) {
        for (size_t j = i + 1; j < collisionables.size(); j++) {
            std::pair<GameObject*, GameObject*> registryEntry(collisionables[i], collisionables[j]);

            //std::cout << "Verificando el  par " << i << "-" << j << std::endl;  // Debug
            if (collisionables[i]->isColliding(collisionables[j])) {
                //std::cout << "Colisión detectada entre " << i << " y " << j << "-" << (int)collisionables[i]->GetPhysType() << "-" << (int)collisionables[j]->GetPhysType() << std::endl;  // Debug
                SolveCollisions(collisionables[i], collisionables[j]);

                if (std::find(collisionRegistry.begin(), collisionRegistry.end(), registryEntry) == collisionRegistry.end()) {
                    collisionables[i]->OnCollisionEnter(collisionables[j]);
                    collisionables[j]->OnCollisionEnter(collisionables[i]);
                    collisionRegistry.push_back(registryEntry);
                }
                else {
                    collisionables[i]->OnCollisionStay(collisionables[j]);
                    collisionables[j]->OnCollisionStay(collisionables[i]);
                }
            }
            else {
                if (std::find(collisionRegistry.begin(), collisionRegistry.end(), registryEntry) != collisionRegistry.end()) {
                    collisionables[i]->OnCollisionExit(collisionables[j]);
                    collisionables[j]->OnCollisionExit(collisionables[i]);
                    collisionRegistry.remove(registryEntry);
                }
            }
        }
    }
    //PrintCollisionables();
}

void CollisionsHandler::PrintCollisionables()
{
    std::cout << "Contenido de collisionables:" << std::endl;

    if (collisionables.empty()) {
        std::cout << "No hay objetos en collisionables." << std::endl;
    }
    else {
        for (auto obj : collisionables) {
            if (obj) {
                // Supongo que GameObject tiene un método ToString o algo similar
                std::cout << obj << std::endl;
            }
            else {
                std::cout << "Objeto nulo encontrado en collisionables." << std::endl;
            }
        }
    }
}


