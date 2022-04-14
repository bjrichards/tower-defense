#pragma once

#include <Aspect.h>
// #include <Square.h>

class Square;
class Physics : public Aspect
{
public:
    Physics(Entity *ent);
    ~Physics();

    virtual void Tick(double dt);

    Entity *entity;
};