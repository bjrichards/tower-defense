#pragma once

#include <SDL2/SDL.h>
#include <Mgr.h>

class EntityMgr : public Mgr
{
public:
    EntityMgr(Engine *engine);
    ~EntityMgr();

    void Init();
    void Tick(uint32_t dt);
    void Stop();

private:
};