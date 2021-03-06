#pragma once

#include <GfxMgr.h>
#include <InputMgr.h>
#include <EntityMgr.h>
#include <GameMgr.h>

class EntityMgr;

class Engine
{
public:
    Engine();
    ~Engine();

    void Init();
    void Run();
    void TickAll(double dt);
    void Cleanup();

    bool m_keep_running;

    uint32_t m_fps_current;

    GfxMgr *gfx_mgr;
    InputMgr *input_mgr;
    EntityMgr *entity_mgr;
    GameMgr *game_mgr;
};