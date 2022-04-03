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
}

void EntityMgr::Tick(uint32_t dt)
{
}

void EntityMgr::Stop()
{
}
