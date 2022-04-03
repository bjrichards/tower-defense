#include <GameMgr.h>
#include <Text.h>
#include <Button.h>
#include <Engine.h>
#include <ButtonTypes.h>
#include <iostream>

GameMgr::GameMgr(Engine *engine) : Mgr(engine)
{
    this->engine = engine;
}

GameMgr::~GameMgr()
{
}

void GameMgr::Init()
{
    this->scene_type = SceneType::Title_Scene;
    Create_Scene_Title();
}

void GameMgr::Tick(uint32_t dt)
{
    // std::cout << scene_type << "\n";
}

void GameMgr::Stop()
{
}

void GameMgr::Button_Clicked(ButtonType bt)
{
    switch (bt)
    {
    case ButtonType::Back_Button:
        std::cout << "Back button pressed!\n";
        scene_type = SceneType::Title_Scene;
        Create_Scene_Title();
        break;
    case ButtonType::Exit_Button:
        std::cout << "Exit button pressed!\n";
        break;
    case ButtonType::Play_Button:
        std::cout << "Play button pressed!\n";
        scene_type = SceneType::Play_Scene;
        Create_Scene_Play();
        break;
    case ButtonType::Settings_Button:
        std::cout << "Settings button pressed!\n";
        break;
    }
}
void GameMgr::Create_Scene_Title()
{
    Clear_Current_Scene();

    // Title of game
    Text *text = new Text(engine->gfx_mgr->m_renderer, "Tower Wars", engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 - 300, 100);
    this->engine->entity_mgr->m_text.push_back(text);

    // Creation of Play, Settings, Exit buttons
    SDL_Rect rect = {engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 - 100, 0, 0};

    Button *button = new Button(engine, rect, "Play", ButtonType::Play_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    rect = {engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2, 0, 0};
    button = new Button(engine, rect, "Settings", ButtonType::Settings_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    rect = {engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 + 100, 0, 0};
    button = new Button(engine, rect, "Exit", ButtonType::Exit_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    for (unsigned int i = 0; i < this->engine->entity_mgr->m_text.size(); i++)
    {
        this->engine->entity_mgr->m_text[i]->Init();
    }

    for (unsigned int i = 0; i < this->engine->entity_mgr->m_button.size(); i++)
    {
        this->engine->entity_mgr->m_button[i]->Init();
    }

    button = NULL;
    delete (button);
    text = NULL;
    delete (text);
}

void GameMgr::Create_Scene_Play()
{
    Clear_Current_Scene();

    SDL_Rect rect = {engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2, 0, 0};

    Button *button = new Button(engine, rect, "Back!", ButtonType::Back_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    for (unsigned int i = 0; i < this->engine->entity_mgr->m_button.size(); i++)
    {
        this->engine->entity_mgr->m_button[i]->Init();
    }

    button = NULL;
    delete (button);
}

void GameMgr::Clear_Current_Scene()
{
    // Clean all buttons and text from previous scene
    for (unsigned int i = this->engine->entity_mgr->m_button.size(); i > 0; i--)
    {
        this->engine->entity_mgr->m_button.pop_back();
    }
    for (unsigned int i = this->engine->entity_mgr->m_text.size(); i > 0; i--)
    {
        this->engine->entity_mgr->m_text.pop_back();
    }
}