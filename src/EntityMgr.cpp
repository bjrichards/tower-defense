#include <EntityMgr.h>
#include <Engine.h>
#include <iostream>

EntityMgr::EntityMgr(Engine *engine) : Mgr(engine)
{
    this->engine = engine;
}

EntityMgr::~EntityMgr()
{
    // Delete all entities
    for (int i = this->entities.size() - 1; i >= 0; --i)
    {
        delete (this->entities[i]);
        this->entities.erase(this->entities.begin() + i);
    }

    // Delete all text
    for (int i = this->m_text.size() - 1; i >= 0; --i)
    {
        delete (this->m_text[i]);
        this->m_text.erase(this->m_text.begin() + i);
    }

    // Delete all buttons
    for (int i = this->m_button.size() - 1; i >= 0; --i)
    {
        delete (this->m_button[i]);
        this->m_button.erase(this->m_button.begin() + i);
    }
}

void EntityMgr::Init()
{
}

void EntityMgr::Tick(uint32_t dt)
{
}

void EntityMgr::Stop()
{
}
