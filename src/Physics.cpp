#include <Physics.h>
#include <Entity.h>
#include <Square.h>
#include <iostream>

Physics::Physics(Entity *ent) : Aspect(ent)
{
    this->entity = ent;
}

Physics::~Physics()
{
}

void Physics::Tick(double dt)
{
    double gravity = 400.0;
    // Apply gravity
    Vector2 temp_vel = entity->Get_Velocity();
    temp_vel.y += dt * gravity;
    Vector2 temp_pos = entity->Get_Position();

    // Change position based on velocity
    temp_pos.x += temp_vel.x * dt;
    temp_pos.y += temp_vel.y * dt;

    entity->Set_Position(temp_pos.x, temp_pos.y);
}