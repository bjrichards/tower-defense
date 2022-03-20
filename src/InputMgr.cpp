#include <InputMgr.h>
#include <Engine.h>

InputMgr::InputMgr(Engine *engine) : Mgr(engine)
{
}

InputMgr::~InputMgr()
{
}

void InputMgr::Init()
{
}

void InputMgr::Tick(uint32_t dt)
{
    while (SDL_PollEvent(&m_window_event) > 0)
    {
        switch (m_window_event.type)
        {
        case SDL_QUIT:
            engine->m_keep_running = false;
            break;
        }
    }
}

void InputMgr::Stop()
{
}