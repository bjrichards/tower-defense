#include <Text.h>
#include <iostream>

Text::Text(SDL_Renderer *renderer, std::string str)
{
    m_renderer = renderer;
    m_str = str;
}

Text::~Text()
{
    SDL_DestroyTexture(m_texture);
    SDL_FreeSurface(m_surface);
    TTF_CloseFont(m_font);
    TTF_Quit();
}

void Text::Init()
{
    TTF_Init();
    m_font = TTF_OpenFont("font/Mali-Regular.ttf", 100);

    m_surface = TTF_RenderText_Solid(m_font, m_str.data(), color);
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

    SDL_QueryTexture(m_texture, NULL, NULL, &m_texW, &m_texH);
    m_dstrect = {0,
                 0,
                 m_texW,
                 m_texH};
}

void Text::Tick(uint32_t dt)
{
    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_dstrect);
}

void Text::Update_Text(std::string str)
{
    m_str = str;
    SDL_DestroyTexture(m_texture);
    SDL_FreeSurface(m_surface);
    m_surface = TTF_RenderText_Solid(m_font, m_str.data(), color);
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_texW, &m_texH);
    m_dstrect = {0,
                 0,
                 m_texW,
                 m_texH};
}

void Text::Stop()
{
}