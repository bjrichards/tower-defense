#pragma once

#include <Mgr.h>
#include <SDL2/SDL.h>

class GfxMgr : public Mgr
{
public:
    GfxMgr(Engine *engine, int win_width, int win_height);
    ~GfxMgr();

    void Init();
    void Tick(uint32_t dt);
    void Stop();

private:
    int m_window_width;
    int m_window_height;
    SDL_Window *m_window;
    SDL_Surface *m_window_surface;
};