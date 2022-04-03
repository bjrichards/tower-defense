#pragma once

#include <SDL2/SDL.h>
#include <Mgr.h>
#include <Text.h>
#include <Button.h>
#include <vector>

class EntityMgr : public Mgr
{
public:
    EntityMgr(Engine *engine);
    ~EntityMgr();

    void Init();
    void Tick(uint32_t dt);
    void Stop();

    Engine *engine;
    std::vector<Text *> m_text;
    std::vector<Button *> m_button;
};