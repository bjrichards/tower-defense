#pragma once

#include <SDL2/SDL.h>
#include <Text.h>
#include <ButtonTypes.h>

class Engine;

class Button
{
public:
    Button(Engine *engine, SDL_Rect rect, std::string str, int font_size, ButtonType bt, SDL_Renderer *renderer);
    ~Button();

    void Init();
    void Tick(double dt);
    void Draw();
    void Stop();
    void Set_Font_Size(int font_size);
    bool Is_Clicked(int mouse_x, int mouse_y);

    ButtonType button_type;

private:
    Engine *engine;
    SDL_Rect m_rect;
    Text *m_text;
};