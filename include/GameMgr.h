#pragma once

#include <SDL2/SDL.h>
#include <Mgr.h>
#include <SceneTypes.h>
#include <ButtonTypes.h>

class GameMgr : public Mgr
{
public:
    GameMgr(Engine *engine);
    ~GameMgr();

    void Init();
    void Tick(uint32_t dt);
    void Stop();

    void Button_Clicked(ButtonType bt);

    void Create_Scene_Title();
    void Create_Scene_Play();
    void Create_Scene_Settings();

    Engine *engine;
    SceneType scene_type;

private:
    void Clear_Current_Scene();
};
