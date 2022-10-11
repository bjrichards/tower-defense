#include <Collision.h>
#include <Entity.h>
#include <iostream>

Collision::Collision(Entity *ent) : Aspect(ent)
{
    this->entity = ent;
}

Collision::~Collision()
{
}

void Collision::Tick(double dt)
{
    // Ensure collides with bottom of window
    Vector2 pos = entity->Get_Position();
    if (entity->Get_Bottom() > entity->engine->gfx_mgr->m_window_height)
    {
        pos.y = entity->engine->gfx_mgr->m_window_height - entity->Get_Height();
        entity->Set_Position(pos.x, pos.y);
    }

    // Check if collides into another entity
    Entity *other;
    for (unsigned int i = 0; i < entity->engine->entity_mgr->entities.size(); i++)
    {
        other = entity->engine->entity_mgr->entities[i];

        if (entity->Get_Identity() != other->Get_Identity())
        {
            if (entity->Get_Right() >= other->Get_Left() && entity->Get_Left() <= other->Get_Right())
            {
                if (entity->Get_Bottom() >= other->Get_Top() && entity->Get_Bottom() <= other->Get_Top() + other->Get_Height() / 2)
                {
                    pos.y = other->Get_Top() - entity->Get_Height();
                    entity->Set_Position(pos.x, pos.y);
                    // std::cout << "Hi" << std::endl;
                }
            }
        }
    }
}