#pragma once

#include <SDL2/SDL.h>
#include <Vector2.h>
#include <vector>
#include <Aspect.h>
#include <EntityTypes.h>
#include <Engine.h>

class Entity
{
public:
    Entity(Engine *engine, Vector2 pos, int identity);
    virtual ~Entity();

    virtual void Init();
    virtual void Tick(double dt);
    virtual void Draw();

    virtual void Set_Position(double x, double y);
    virtual void Set_Velocity(double x, double y);

    virtual Vector2 Get_Position();
    virtual Vector2 Get_Velocity();

    Engine *engine;

    std::string name;
    std::string img_path;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Renderer *renderer = 0;

    EntityTypes entity_type;

    std::vector<Aspect *> aspects;

private:
    // Static data
    int identity;

    // Dynamic data
    Vector2 m_position;
    Vector2 m_velocity;

    float min_speed, max_speed;
    float acceleration, fire_rate;

    float speed;
};