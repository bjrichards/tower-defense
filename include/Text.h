#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text
{
public:
    Text(SDL_Renderer *renderer, std::string str, int posx, int posy, int font_size);
    Text(SDL_Renderer *renderer, std::string str, int posx, int posy, int font_size, SDL_Color color);
    ~Text();

    void Init();
    void Tick(double dt);
    void Draw();
    void Update_Text(std::string str);
    void Update_Font_Size(int font_size);
    void Stop();

    SDL_Rect m_dstrect;

private:
    SDL_Surface *m_surface;
    SDL_Texture *m_texture;
    SDL_Renderer *m_renderer = 0;

    TTF_Font *m_font;
    SDL_Color m_color = {255, 255, 255};
    std::string m_str;
    int m_font_size;
    int m_posx, m_posy;
    int m_texW = 0;
    int m_texH = 0;
};