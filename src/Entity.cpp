#include <Entity.h>
#include <EntityTypes.h>

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

    this->position = pos;
    this->velocity = Vector2();

    this->speed = 0;
    this->fire_rate = 0;
    this->acceleration = 0;
    this->min_speed = 0;
    this->max_speed = 0;

    this->entity_type = EntityTypes::None;
}

Entity::~Entity()
{
    for (int i = this->aspects.size() - 1; i >= 0; --i)
    {
        delete (this->aspects[i]);
        this->aspects.erase(this->aspects.begin() + i);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void Entity::Tick(uint32_t dt)
{
    for (unsigned int i = 0; i < aspects.size(); i++)
    {
        aspects[i]->Tick(dt);
    }
}