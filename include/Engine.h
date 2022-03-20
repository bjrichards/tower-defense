#pragma once

#include <GfxMgr.h>
#include <InputMgr.h>

class Engine
{
public:
    Engine();
    ~Engine();

    void Init();
    void Run();
    void TickAll(uint32_t dt);
    void Cleanup();

    bool m_keep_running;

    GfxMgr *gfx_mgr;
    InputMgr *input_mgr;
};