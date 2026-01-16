#include "Collider.h"

Collider::Collider(ColliderType type) : Transformable({0, 0})
{
    m_type = type;
    m_offsetX = 0;
    m_offsetY = 0;

    m_isActived = true;
}

void Collider::SetOffset(float ox, float oy)
{
    m_offsetX = ox;
    m_offsetY = oy;
}

void Collider::SetPosition(Vector2f position)
{
    Vector2f offset{ m_offsetX, m_offsetY };
    Transformable::SetPosition(position + offset);
}