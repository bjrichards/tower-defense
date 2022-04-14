#pragma once

#include <SDL2/SDL.h>

class Entity; // Forward declaration of the Entity class

class Aspect
{
public:
    Aspect(Entity *ent);
    virtual ~Aspect();

    virtual void Tick(double dt);

    Entity *entity;
};
