#pragma once
#include "Transformable.h"
#include "Movable.h"
#include "Drawable.h"
#include <string>

class Sprite;
class Collider;

class Entity : public Transformable, public Movable, public Drawable
{
protected:
	Sprite* m_sprite;
	Collider* m_collider;

	bool m_isDestroyed;

public:
	Entity(Collider* collider, float speed);
	virtual ~Entity();

	virtual void SetPosition(Vector2f position) override;
	virtual void Move(float deltaTime) override;

	virtual void Update(SDL_Renderer* renderer, float deltaTime);
	virtual void Draw(SDL_Renderer* renderer) override;

	virtual void SetSprite(SDL_Renderer* renderer, std::string filepath);

	virtual void Destroy();

	Sprite* GetSprite() const { return m_sprite; }
	Collider* GetCollider() const { return m_collider; }
};

