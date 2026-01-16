#pragma once
#include <SDL.h>
#include "Transformable.h"
#include "Drawable.h" // DEBUG

enum class ColliderType
{
    Rectangle,
    Circle
};

class Collider : public Transformable, public Drawable // DEBUG
{
protected:
    float m_offsetX;
    float m_offsetY;
    ColliderType m_type;

    bool m_isActived;

public:
    Collider(ColliderType type);
    virtual ~Collider() {}

    ColliderType GetType() const { return m_type; }

    virtual void SetOffset(float ox, float oy);
    virtual void SetPosition(Vector2f position) override;
    virtual void SetActive(bool value) { m_isActived = value; }

    virtual bool IsActived() { return m_isActived; }

    virtual bool IsColliding(Collider* other) = 0;

    virtual float GetLeft() = 0;
    virtual float GetRight() = 0;
    virtual float GetTop() = 0;
    virtual float GetBottom() = 0;
};
