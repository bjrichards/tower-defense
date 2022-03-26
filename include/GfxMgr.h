#pragma once

#include <SDL2/SDL.h>
#include <Mgr.h>

class GfxMgr : public Mgr
{
public:
    GfxMgr(Engine *engine, int win_width, int win_height);
    ~GfxMgr();

    void Init();
    void Tick(uint32_t dt);
    void Stop();

    int m_window_width = 0;
    int m_window_height = 0;
    SDL_Window *m_window;
    SDL_Surface *m_window_surface;
    SDL_Renderer *m_renderer;
};