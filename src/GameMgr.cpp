#include <GameMgr.h>
#include <Text.h>
#include <Button.h>
#include <Engine.h>
#include <ButtonTypes.h>
#include <Square.h>
#include <iostream>
#include <Utilities.h>

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

void GameMgr::Tick(double dt)
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
    case ButtonType::Main_Menu_Button:
        std::cout << "Title button pressed!\n";
        scene_type = SceneType::Title_Scene;
        Create_Scene_Title();
        break;
    case ButtonType::Cube_Drop_Button:
        std::cout << "Cube drop button pressed!\n";
        scene_type = SceneType::Cube_Drop_Scene;
        Create_Scene_Cube_Drop();
        break;
    case ButtonType::Exit_Button:
        std::cout << "Exit button pressed!\n";
        engine->m_keep_running = false;
        break;
    case ButtonType::Play_Button:
        std::cout << "Play button pressed!\n";
        scene_type = SceneType::Play_Scene;
        Create_Scene_Play();
        break;
    case ButtonType::Settings_Button:
        std::cout << "Settings button pressed!\n";
        scene_type = SceneType::Settings_Scene;
        Create_Scene_Settings();
        break;
    case ButtonType::Level_1_Button:
        std::cout << "Level 1 button pressed!\n";
        scene_type = SceneType::Level_Scene;
        Create_Scene_Level(1);
        break;
    }
}
void GameMgr::Create_Scene_Title()
{
    Clear_Current_Scene();

    Text *text = new Text(engine->gfx_mgr->m_renderer, "Tower Wars", engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 - 300, 100);
    // Title of game
    this->engine->entity_mgr->m_text.push_back(text);

    // Creation of Play, Settings, Exit buttons
    SDL_Rect rect = {engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2, 0, 0};

    Button *button = new Button(engine, rect, "Play", 100, ButtonType::Play_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    rect = {engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 + 150, 0, 0};
    button = new Button(engine, rect, "Cube Drop", 80, ButtonType::Cube_Drop_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    rect = {engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 + 300, 0, 0};
    button = new Button(engine, rect, "Settings", 80, ButtonType::Settings_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    rect = {100, engine->gfx_mgr->m_window_height - 50, 0, 0};
    button = new Button(engine, rect, "Exit", 40, ButtonType::Exit_Button, engine->gfx_mgr->m_renderer);
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

    SDL_Rect rect = {150, 150, 0, 0};

    Button *button = new Button(engine, rect, "[1]", 100, ButtonType::Level_1_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    rect = {150, engine->gfx_mgr->m_window_height - 50, 0, 0};
    button = new Button(engine, rect, "Back!", 100, ButtonType::Back_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    for (unsigned int i = 0; i < this->engine->entity_mgr->m_button.size(); i++)
    {
        this->engine->entity_mgr->m_button[i]->Init();
    }
    for (unsigned int i = 0; i < this->engine->entity_mgr->entities.size(); i++)
    {
        this->engine->entity_mgr->entities[i]->Init();
    }

    button = NULL;
    delete (button);
}

void GameMgr::Create_Scene_Cube_Drop()
{
    Clear_Current_Scene();

    // Add squares
    int counter = 0;
    for (int i = 0; i <= engine->gfx_mgr->m_window_width / 100; i++)
    {
        for (int j = 0; j <= engine->gfx_mgr->m_window_height / 100; j++, counter++)
        {
            Vector2 vec = {(double)(i * 100), (double)(0 - (i * 40) - (j * 200))};
            Square *square = new Square(engine, vec, counter);
            engine->entity_mgr->entities.push_back(square);
        }
    }

    SDL_Rect rect = {150, engine->gfx_mgr->m_window_height - 50, 0, 0};

    Button *button = new Button(engine, rect, "Back!", 100, ButtonType::Back_Button, engine->gfx_mgr->m_renderer);
    this->engine->entity_mgr->m_button.push_back(button);

    for (unsigned int i = 0; i < this->engine->entity_mgr->m_button.size(); i++)
    {
        this->engine->entity_mgr->m_button[i]->Init();
    }
    for (unsigned int i = 0; i < this->engine->entity_mgr->entities.size(); i++)
    {
        this->engine->entity_mgr->entities[i]->Init();
    }

    button = NULL;
    delete (button);
}

void GameMgr::Create_Scene_Settings()
{
    Clear_Current_Scene();

    Text *text = new Text(engine->gfx_mgr->m_renderer, "Settings", engine->gfx_mgr->m_window_width / 2, engine->gfx_mgr->m_window_height / 2 - 300, 60);
    // Title of game
    this->engine->entity_mgr->m_text.push_back(text);

    SDL_Rect rect = {150, engine->gfx_mgr->m_window_height - 50, 0, 0};

    Button *button = new Button(engine, rect, "Back!", 100, ButtonType::Back_Button, engine->gfx_mgr->m_renderer);
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

void GameMgr::Create_Scene_Level(int level_num)
{
    Clear_Current_Scene();

    Text *text = new Text(engine->gfx_mgr->m_renderer, "Level " + utilities::IntToString(level_num), engine->gfx_mgr->m_window_width / 2, 50, 60);
    this->engine->entity_mgr->m_text.push_back(text);

    SDL_Rect rect = {150, engine->gfx_mgr->m_window_height - 50, 0, 0};

    Button *button = new Button(engine, rect, "Menu", 100, ButtonType::Main_Menu_Button, engine->gfx_mgr->m_renderer);
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

void GameMgr::Clear_Current_Scene()
{
    // Clean all buttons and text from previous scene
    for (int i = this->engine->entity_mgr->m_button.size() - 1; i >= 0; --i)
    {
        delete (this->engine->entity_mgr->m_button[i]);
        this->engine->entity_mgr->m_button.erase(this->engine->entity_mgr->m_button.begin() + i);
    }
    for (int i = this->engine->entity_mgr->m_text.size() - 1; i >= 0; --i)
    {
        delete (this->engine->entity_mgr->m_text[i]);
        this->engine->entity_mgr->m_text.erase(this->engine->entity_mgr->m_text.begin() + i);
    }

    for (int i = this->engine->entity_mgr->entities.size() - 1; i >= 0; --i)
    {
        delete (this->engine->entity_mgr->entities[i]);
        this->engine->entity_mgr->entities.erase(this->engine->entity_mgr->entities.begin() + i);
    }
}