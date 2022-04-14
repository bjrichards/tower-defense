#include <SDL2/SDL.h>
#include <Engine.h>

#include <iostream>

#define FPS_INTERVAL 1.0 // seconds

Engine::Engine()
{
    this->m_keep_running = true;
    this->gfx_mgr = 0;
    this->input_mgr = 0;
    this->entity_mgr = 0;
    this->game_mgr = 0;

    this->m_fps_current = 0;
}

Engine::~Engine()
{
    delete (this->gfx_mgr);
    delete (this->input_mgr);
    delete (this->entity_mgr);
    delete (this->game_mgr);
    SDL_Quit();
}

void Engine::Init()
{
    this->gfx_mgr = new GfxMgr(this, 1920, 1080);
    this->input_mgr = new InputMgr(this);
    this->entity_mgr = new EntityMgr(this);
    this->game_mgr = new GameMgr(this);

    this->gfx_mgr->Init();
    std::cout << "Graphics Manager initialized\n";
    this->input_mgr->Init();
    std::cout << "Input Manager initialized\n";
    this->entity_mgr->Init();
    std::cout << "Entity Manager initialized\n";
    this->game_mgr->Init();
    std::cout << "Game Manager initialized\n";
}

void Engine::TickAll(double dt)
{
    game_mgr->Tick(dt);
    input_mgr->Tick(dt);
    entity_mgr->Tick(dt);
    gfx_mgr->Tick(dt);
}

void Engine::Run()
{
    // for dt
    uint32_t last_tick_time = 0;
    uint32_t tick_time = 0;

    // for fps
    uint32_t fps_last_time = SDL_GetTicks();
    uint32_t fps_frames = 0;
    while (m_keep_running)
    {
        // get dt
        double dt = 0.0;
        tick_time = SDL_GetTicks();
        dt = (double)(tick_time - last_tick_time) / (double)100;
        last_tick_time = tick_time;

        // tick all
        TickAll(dt);

        // get fps
        fps_frames++;
        if (fps_last_time < SDL_GetTicks() - FPS_INTERVAL * 1000)
        {
            fps_last_time = SDL_GetTicks();
            m_fps_current = fps_frames;
            fps_frames = 0;
        }
    }
}

void Engine::Cleanup()
{
    gfx_mgr->Stop();
    input_mgr->Stop();
    entity_mgr->Stop();
    game_mgr->Stop();
}