#include <Engine.h>

#include <iostream>

Engine::Engine()
{
    gfx_mgr = 0;
    input_mgr = 0;
    m_keep_running = true;
}

Engine::~Engine()
{
}

void Engine::Init()
{
    gfx_mgr = new GfxMgr(this, 680, 480);
    input_mgr = new InputMgr(this);

    gfx_mgr->Init();
    input_mgr->Init();
}

void Engine::TickAll(uint32_t dt)
{
    gfx_mgr->Tick(dt);
    input_mgr->Tick(dt);
}

void Engine::Run()
{
    uint32_t last_tick_time = 0;
    uint32_t tick_time = 0;
    while (m_keep_running)
    {
        uint32_t dt = 0.0;
        tick_time = SDL_GetTicks();
        dt = tick_time - last_tick_time;
        last_tick_time = tick_time;
        TickAll(dt);
    }
}

void Engine::Cleanup()
{

    gfx_mgr->Stop();
    input_mgr->Stop();
}