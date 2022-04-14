#include <Entity.h>
#include <EntityTypes.h>

#include <iostream>

std::string IntToString(int x)
{
    char tmp[10000];
    sprintf(tmp, "%i", x);
    return std::string(tmp);
}

Entity::Entity(Engine *engine, Vector2 pos, int identity)
{
    this->engine = engine;

    this->identity = identity;

    this->m_position = pos;
    this->m_velocity = Vector2();

    this->speed = 0;
    this->fire_rate = 0;
    this->acceleration = 0;
    this->min_speed = 0;
    this->max_speed = 0;

    this->entity_type = EntityTypes::None;
}

Entity::~Entity()
{
    // for (int i = this->aspects.size() - 1; i >= 0; --i)
    // {
    //     delete (this->aspects[i]);
    //     this->aspects.erase(this->aspects.begin() + i);
    // }

    // SDL_DestroyTexture(texture);
    // SDL_FreeSurface(surface);
}

void Entity::Init()
{
}

void Entity::Tick(double dt)
{
    std::cout << "Hi";
}

void Entity::Draw()
{
}

void Entity::Set_Position(double x, double y)
{
    m_position = {x, y};
}

void Entity::Set_Velocity(double x, double y)
{
    m_velocity = {x, y};
}

Vector2 Entity::Get_Position()
{
    return m_position;
}

Vector2 Entity::Get_Velocity()
{
    return m_velocity;
}
