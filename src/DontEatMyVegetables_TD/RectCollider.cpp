#include "RectCollider.h"
#include "CircleCollider.h"
#include <algorithm>

bool RectCollider::IsColliding(Collider* other)
{
    if (m_isActived == false || other->IsActived() == false)
        return false;

    if (other->GetType() == ColliderType::Rectangle)
    {
        RectCollider* r = (RectCollider*)other;

        return !(GetRight() < r->GetLeft() ||
            GetLeft() > r->GetRight() ||
            GetBottom() < r->GetTop() ||
            GetTop() > r->GetBottom());
    }
    else // Circle
    {
        CircleCollider* c = (CircleCollider*)other;

        float radius = c->GetRadius();

        // clamp du point du cercle dans le rectangle
        float closestX = std::max(GetLeft(), std::min(m_pos.GetX(), GetRight()));
        float closestY = std::max(GetTop(), std::min(m_pos.GetY(), GetBottom()));

        float dx = closestX - m_pos.GetX();
        float dy = closestY - m_pos.GetY();

        return dx * dx + dy * dy <= radius * radius;
    }
}
