#pragma once

#include <Mgr.h>
#include <SDL2/SDL.h>

class InputMgr : public Mgr
{
public:
    InputMgr(Engine *engine);
    ~InputMgr();

    void Init();
    void Tick(uint32_t dt);
    void Stop();

private:
    SDL_Event m_window_event;
};