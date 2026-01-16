#pragma once
#include "Collider.h"

class CircleCollider : public Collider
{
private:
    float m_radius;

public:
    CircleCollider(float radius) : Collider(ColliderType::Circle), m_radius(radius) {}

    float GetRadius() const { return m_radius; }

    bool IsColliding(Collider* other) override;

    void Draw(SDL_Renderer* renderer) override
    {
        for (int i = 0; i < 360; i++)
        {
            float rad = i * M_PI / 180.f;
            int px = m_pos.GetX() + cos(rad) * m_radius;
            int py = m_pos.GetY() + sin(rad) * m_radius;
            SDL_RenderDrawPoint(renderer, px, py);
        }
    }

    float GetLeft() override { return m_pos.GetX() - m_radius; }
    float GetRight() override { return m_pos.GetX() + m_radius; }
    float GetTop() override { return m_pos.GetY() - m_radius; }
    float GetBottom() override { return m_pos.GetY() + m_radius; }
};
