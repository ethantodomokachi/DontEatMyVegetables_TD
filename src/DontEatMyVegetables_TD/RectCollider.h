#pragma once
#include "Collider.h"

class RectCollider : public Collider
{
private:
    float m_width;
    float m_height;

public:
    RectCollider(float width, float height) : Collider(ColliderType::Rectangle), m_width(width), m_height(height) {}

    float GetLeft() override { return m_pos.GetX() - m_width * 0.5f; }
    float GetRight() override { return m_pos.GetX() + m_width * 0.5f; }
    float GetTop() override { return m_pos.GetY() - m_height * 0.5f; }
    float GetBottom() override { return m_pos.GetY() + m_height * 0.5f; }

    bool IsColliding(Collider* other) override;

    void Draw(SDL_Renderer* renderer) override
    {
        SDL_Rect r;
        r.x = (int)(m_pos.GetX() - m_width * 0.5f);
        r.y = (int)(m_pos.GetY() - m_height * 0.5f);
        r.w = (int)m_width;
        r.h = (int)m_height;

        SDL_RenderDrawRect(renderer, &r);
    }
};
