#include <EntityMgr.h>
#include <Engine.h>
#include <iostream>

EntityMgr::EntityMgr(Engine *engine) : Mgr(engine)
{
    this->engine = engine;
}

EntityMgr::~EntityMgr()
{
}

void EntityMgr::Init()
{
    Create_Screen_Title();
}

void EntityMgr::Tick(uint32_t dt)
{
}

void EntityMgr::Stop()
{
}

void EntityMgr::Create_Screen_Title()
{
    Text *text = new Text(engine->gfx_mgr->m_renderer, "Tower Wars", engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 - 300, 100);
    m_text.push_back(text);

    SDL_Color color = {200, 200, 255};
    text = new Text(engine->gfx_mgr->m_renderer, "Play", engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 - 100, 60, color);
    m_text.push_back(text);

    text = new Text(engine->gfx_mgr->m_renderer, "Settings", engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2, 60, color);
    m_text.push_back(text);

    text = new Text(engine->gfx_mgr->m_renderer, "Exit", engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 + 100, 60, color);
    m_text.push_back(text);

    for (unsigned int i = 0; i < m_text.size(); i++)
    {
        m_text[i]->Init();
    }
}