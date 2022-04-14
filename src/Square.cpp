#include <Square.h>
#include <Utilities.h>
#include <Entity.h>
#include <Physics.h>
#include <Collision.h>
#include <iostream>

Square::Square(Engine *engine, Vector2 pos, int identity) : Entity(engine, pos, identity)
{
    this->engine = engine;
    this->identity = identity;

    this->m_position.x = pos.x;
    this->m_position.y = pos.y;
    this->m_velocity = Vector2();

    this->m_height = 100;
    this->m_width = 100;

    this->speed = 2;
    this->fire_rate = 0;
    this->acceleration = 0;
    this->min_speed = 0;
    this->max_speed = 0;

    this->entity_type = EntityTypes::Square_Entity;

    this->renderer = this->engine->gfx_mgr->m_renderer;
}

Square::~Square()
{
}

void Square::Init()
{
    Physics *phy = new Physics((Entity *)this);
    aspects.push_back((Aspect *)phy);

    Collision *col = new Collision((Entity *)this);
    aspects.push_back((Aspect *)col);
}

void Square::Tick(double dt)
{
    for (unsigned int i = 0; i < aspects.size(); i++)
    {
        aspects[i]->Tick(dt);
    }
}

void Square::Draw()
{
    SDL_Rect rect = {(int)m_position.x, (int)m_position.y, m_width, m_height};

    SDL_SetRenderDrawColor(renderer, 139, 0, 139, 255);
    SDL_RenderFillRect(renderer, &rect);

    rect = {(int)m_position.x + 10, (int)m_position.y + 10, m_width - 20, m_height - 20};

    SDL_SetRenderDrawColor(renderer, 70, 0, 130, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 45, 164, 132, SDL_ALPHA_OPAQUE);
}

void Square::Set_Position(double x, double y)
{
    m_position = {x, y};
}

void Square::Set_Velocity(double x, double y)
{
    m_velocity = {x, y};
}

Vector2 Square::Get_Position()
{
    return m_position;
}

Vector2 Square::Get_Velocity()
{
    return m_velocity;
}

int Square::Get_Height()
{
    return m_height;
}

int Square::Get_Width()
{
    return m_width;
}

double Square::Get_Top()
{
    return m_position.y;
}

double Square::Get_Bottom()
{
    return m_position.y + m_height;
}

double Square::Get_Left()
{
    return m_position.x;
}

double Square::Get_Right()
{
    return m_position.x + m_width;
}

int Square::Get_Identity()
{
    return identity;
}