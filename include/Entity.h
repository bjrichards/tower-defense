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
    ~Entity();

    void Init();
    void Tick(uint32_t dt);

    Engine *engine;

    std::vector<Aspect *> aspects;

    // Static data
    int identity;

    std::string name;
    std::string img_path;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Renderer *renderer = 0;

    float min_speed, max_speed;
    float acceleration, fire_rate;

    EntityTypes entity_type;

    // Dynamic data
    Vector2 position;
    Vector2 velocity;
    float speed;
};