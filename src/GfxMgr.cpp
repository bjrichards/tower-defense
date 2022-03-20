#include <GfxMgr.h>
#include <iostream>

GfxMgr::GfxMgr(Engine *engine, int win_width, int win_height) : Mgr(engine)
{
    m_window_width = win_width;
    m_window_height = win_height;
}

GfxMgr::~GfxMgr()
{
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

void GfxMgr::Init()
{
    m_window = SDL_CreateWindow("Tower Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_window_width, m_window_height, 0);
    if (!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);

    if (!m_window_surface)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
}

void GfxMgr::Tick(uint32_t dt)
{
    SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(m_window);
}

void GfxMgr::Stop()
{
}