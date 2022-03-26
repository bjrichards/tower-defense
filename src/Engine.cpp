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

    this->m_fps_current = 0;
}

Engine::~Engine()
{
    delete (gfx_mgr);
    delete (input_mgr);
    delete (entity_mgr);
    SDL_Quit();
}

void Engine::Init()
{
    gfx_mgr = new GfxMgr(this, 1920, 1080);
    input_mgr = new InputMgr(this);
    entity_mgr = new EntityMgr(this);

    gfx_mgr->Init();
    std::cout << "Graphics Manager initialized\n";
    input_mgr->Init();
    std::cout << "Input Manager initialized\n";
    entity_mgr->Init();
    std::cout << "Entity Manager initialized\n";
}

void Engine::TickAll(uint32_t dt)
{
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
    entity_mgr->Create_Screen_Title();
    while (m_keep_running)
    {
        // get dt
        uint32_t dt = 0.0;
        tick_time = SDL_GetTicks();
        dt = tick_time - last_tick_time;
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
}