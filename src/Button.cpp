#include <Button.h>

Button::Button(Engine *engine, SDL_Rect rect, std::string str, int font_size, ButtonType bt, SDL_Renderer *renderer)
{
    this->engine = engine;
    this->m_rect = rect;
    this->button_type = bt;

    // Text stuff
    SDL_Color color = {200, 200, 255};
    m_text = new Text(renderer, str, m_rect.x, m_rect.y, font_size, color);
}

Button::~Button()
{
    this->engine = NULL;
    delete (this->m_text);
}

void Button::Init()
{
    m_text->Init();

    m_rect.h = m_text->m_dstrect.h;
    m_rect.w = m_text->m_dstrect.w;
}

void Button::Tick(double dt)
{
}

void Button::Draw()
{
    m_text->Draw();
}

void Button::Stop()
{
}

void Button::Set_Font_Size(int font_size)
{
    m_text->Update_Font_Size(font_size);
}

bool Button::Is_Clicked(int mouse_x, int mouse_y)
{
    // Check if button clicked
    if (mouse_x >= m_rect.x - m_rect.w / 2 && mouse_x <= m_rect.x + m_rect.w / 2)
    {
        if (mouse_y >= m_rect.y - m_rect.h / 2 && mouse_y <= m_rect.y + m_rect.h / 2)
        {
            return true;
        }
    }
    return false;
}