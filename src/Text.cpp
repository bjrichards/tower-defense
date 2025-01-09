#include <Text.h>
#include <iostream>

Text::Text(SDL_Renderer *renderer, std::string str, int posx, int posy, int font_size)
{
    m_renderer = renderer;
    m_str = str;
    m_posx = posx;
    m_posy = posy;
    m_font_size = font_size;
}

Text::Text(SDL_Renderer *renderer, std::string str, int posx, int posy, int font_size, SDL_Color color)
{
    m_renderer = renderer;
    m_str = str;
    m_posx = posx;
    m_posy = posy;
    m_font_size = font_size;
    m_color = color;
}

Text::~Text()
{
    SDL_DestroyTexture(m_texture);
    SDL_FreeSurface(m_surface);
    TTF_CloseFont(m_font);
}

void Text::Init()
{

    m_font = TTF_OpenFont("font/Mali-Regular.ttf", m_font_size);

    m_surface = TTF_RenderText_Blended(m_font, m_str.data(), m_color);
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

    SDL_QueryTexture(m_texture, NULL, NULL, &m_texW, &m_texH);

    m_dstrect = {m_posx - m_texW / 2,
                 m_posy - m_texH / 2,
                 m_texW,
                 m_texH};
}

void Text::Tick(double dt)
{
    // SDL_RenderCopy(m_renderer, m_texture, NULL, &m_dstrect);
}

void Text::Draw()
{
    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_dstrect);
}

void Text::Update_Text(std::string str)
{
    m_str = str;
    SDL_DestroyTexture(m_texture);
    SDL_FreeSurface(m_surface);
    m_surface = TTF_RenderText_Solid(m_font, m_str.data(), m_color);
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_texW, &m_texH);
    m_dstrect = {m_posx - m_texW / 2,
                 m_posy - m_texH / 2,
                 m_texW,
                 m_texH};
}

void Text::Update_Font_Size(int font_size)
{
}

void Text::Stop()
{
}