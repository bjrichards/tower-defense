#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text
{
public:
    Text(SDL_Renderer *renderer, std::string str);
    ~Text();

    void Init();
    void Tick(uint32_t dt);
    void Update_Text(std::string str);
    void Stop();

private:
    SDL_Surface *m_surface;
    SDL_Texture *m_texture;
    SDL_Renderer *m_renderer;

    TTF_Font *m_font;
    SDL_Color color = {255, 255, 255};
    std::string m_str;
    int m_texW, m_texH = 0;
    SDL_Rect m_dstrect;
};