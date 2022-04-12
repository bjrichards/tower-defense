#include <InputMgr.h>
#include <Engine.h>
#include <iostream>

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
        case SDL_MOUSEBUTTONDOWN:
            if (m_window_event.button.button == SDL_BUTTON_LEFT)
            {
                int x, y;

                SDL_GetMouseState(&x, &y);

                for (unsigned int i = 0; i < this->engine->entity_mgr->m_button.size(); i++)
                {
                    if (this->engine->entity_mgr->m_button[i]->Is_Clicked(x, y))
                    {
                        this->engine->game_mgr->Button_Clicked(this->engine->entity_mgr->m_button[i]->button_type);
                        break;
                    }
                }
            }
            break;
        }
    }
}

void InputMgr::Stop()
{
}