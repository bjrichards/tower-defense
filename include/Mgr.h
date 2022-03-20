#pragma once
#include <stdint.h>

class Engine;

class Mgr
{
public:
    Mgr(Engine *engine);
    virtual ~Mgr();

    Engine *engine;

    virtual void Init();
    virtual void Tick(uint32_t dt);
    virtual void Stop();
};
