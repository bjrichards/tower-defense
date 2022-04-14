#pragma once

#include <Aspect.h>

class Collision : public Aspect
{
public:
    Collision(Entity *ent);
    ~Collision();

    virtual void Tick(double dt);

    Entity *entity;
};