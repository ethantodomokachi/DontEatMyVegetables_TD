#include "CircleCollider.h"
#include "RectCollider.h"

bool CircleCollider::IsColliding(Collider* other)
{
    if (m_isActived == false || other->IsActived() == false)
        return false;

    if (other->GetType() == ColliderType::Circle)
    {
        CircleCollider* c = (CircleCollider*)other;

        float dx = c->m_pos.GetX() - m_pos.GetX();
        float dy = c->m_pos.GetY() - m_pos.GetY();
        float r = c->m_radius + m_radius;

        return dx * dx + dy * dy <= r * r;
    }
    else
    {
        return other->IsColliding(this);
    }
}
