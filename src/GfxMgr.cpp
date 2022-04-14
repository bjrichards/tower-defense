#include <GfxMgr.h>
#include <Engine.h>
#include <iostream>

GfxMgr::GfxMgr(Engine *engine, int win_width, int win_height) : Mgr(engine)
{
    m_window_width = win_width;
    m_window_height = win_height;
}

GfxMgr::~GfxMgr()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
    TTF_Quit();
}

void GfxMgr::Init()
{
    // Initialize SDL
    if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) == -1))
    {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
    TTF_Init();

    m_window = SDL_CreateWindow("Tower Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_window_width, m_window_height, 0);
    if (!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (!m_renderer)
    {
        std::cout << "Failed to create renderer\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    // Set default colour to turquise
    SDL_SetRenderDrawColor(m_renderer, 45, 164, 132, SDL_ALPHA_OPAQUE);
}

void GfxMgr::Tick(double dt)
{
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 45, 164, 132, SDL_ALPHA_OPAQUE);

    for (unsigned int i = 0; i < engine->entity_mgr->entities.size(); i++)
    {
        engine->entity_mgr->entities[i]->Draw();
    }
    for (unsigned int i = 0; i < engine->entity_mgr->m_text.size(); i++)
    {
        engine->entity_mgr->m_text[i]->Draw();
    }
    for (unsigned int i = 0; i < engine->entity_mgr->m_button.size(); i++)
    {
        engine->entity_mgr->m_button[i]->Draw();
    }

    SDL_RenderPresent(m_renderer);
}

void GfxMgr::Stop()
{
}