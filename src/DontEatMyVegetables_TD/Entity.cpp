#include "Entity.h"
#include "Sprite.h"
#include "Collider.h"

Entity::Entity(Collider* collider, float speed) : Transformable({0, 0}), Movable(speed, {0, 0})
{
	m_sprite = nullptr;
	m_collider = collider;
	
	m_isDestroyed = false;
}

Entity::~Entity()
{
	delete m_collider;
	delete m_sprite;
}

void Entity::SetPosition(Vector2f position)
{
	Transformable::SetPosition(position);

	m_sprite->SetPosition(position);
	m_collider->SetPosition(position);
}

void Entity::Move(float deltaTime)
{
	Vector2f pos{ m_dir.GetX() * m_speed * deltaTime, m_dir.GetY() * m_speed * deltaTime};
	SetPosition(pos);
}

void Entity::Update(SDL_Renderer* renderer, float deltaTime)
{
	Move(deltaTime);
}

void Entity::Draw(SDL_Renderer* renderer)
{
	if (m_sprite == nullptr)
		return;

	m_sprite->Draw(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);		// DEBUG
	m_collider->Draw(renderer);								// DEBUG
}

void Entity::SetSprite(SDL_Renderer* renderer, std::string filepath)
{
	if (m_sprite)
		delete m_sprite;

	m_sprite = new Sprite(renderer, filepath);
}

void Entity::Destroy()
{
	m_isDestroyed = true;
}
