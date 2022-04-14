#pragma once

#include <Entity.h>
#include <Engine.h>
#include <Vector2.h>
// #include <Aspect.h>

class Aspect;

// #include <Physics.h>

class Square : public Entity
{
public:
    Square(Engine *engine, Vector2 pos, int identity);
    ~Square();

    void Init();
    void Tick(double dt);
    void Draw();

    void Set_Position(double x, double y);
    void Set_Velocity(double x, double y);

    Vector2 Get_Position();
    Vector2 Get_Velocity();

    int Get_Height();
    int Get_Width();

    double Get_Top();
    double Get_Bottom();
    double Get_Left();
    double Get_Right();

    int Get_Identity();

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

    int m_height;
    int m_width;

    // Dynamic data
    Vector2 m_position;
    Vector2 m_velocity;

    float min_speed, max_speed;
    float acceleration, fire_rate;

    float speed;
};