#include <Aspect.h>
#include <Entity.h>

#include <iostream>

Aspect::Aspect(Entity *ent)
{
    this->entity = ent;
}

Aspect::~Aspect()
{
}

void Aspect::Tick(double dt)
{
}
