#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <utility>
#include "GameObject.h"

class CollisionsHandler
{
    public:
        enum PhysicsType {
            None,
            Static,
            Dynamic
        };

        static std::vector<GameObject*> collisionables;
        static std::list<std::pair<GameObject*, GameObject*>> collisionRegistry;

        // Métodos estáticos
        static void AddObject(GameObject* obj);
        static void RemoveObject(GameObject* obj);
        static void Reset();
        static void SolvePhysics(GameObject* first, GameObject* second);
        static void SolveCollisions(GameObject* first, GameObject* second);
        static void Update();
        static void PrintCollisionables();
};

