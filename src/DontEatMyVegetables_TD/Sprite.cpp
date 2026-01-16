#include <iostream>
#include "Sprite.h"
#include "AssetManager.h"

Sprite::Sprite(SDL_Renderer* r, const char* fp) : Transformable({ 0, 0 })
{
	m_filePath = fp;

	AssetManager& am = AssetManager::Get();

	TextureData* tData = am.LoadTexture(fp, r);

	if (tData == nullptr)
	{
		std::cout << "Error tData Load" << std::endl;
		exit(0);
	}

	m_texture = tData->texture;
	m_frameWidth = tData->width;
	m_frameHeight = tData->height;

	m_angle = 0.f;
	m_flip = SDL_FLIP_NONE;
	m_rotationCenter = { -1, -1 };
}

void Sprite::SetSpriteSheet(int frameWidth, int frameHeight)
{
	m_frameWidth = frameWidth;
	m_frameHeight = frameHeight;
}

SDL_Rect Sprite::GetFrame(int x, int y) const
{
	return SDL_Rect{
		x * m_frameWidth,
		y * m_frameHeight,
		m_frameWidth,
		m_frameHeight
	};
}

void Sprite::Resize(int width, int height)
{
	float scaleX = (float)width / m_frameWidth;
	float scaleY = (float)height / m_frameHeight;
	float scale = std::min(scaleX, scaleY);

	m_frameWidth *= scale;
	m_frameHeight *= scale;
}

void Sprite::SetRotation(float angle)
{
	m_angle = angle;
}

void Sprite::SetFlip(SDL_RendererFlip flip)
{
	m_flip = flip;
}

void Sprite::SetRotationCenter(int x, int y)
{
	m_rotationCenter = { x, y };
}

void Sprite::ResetTransform()
{
	m_angle = 0.f;
	m_flip = SDL_FLIP_NONE;
	m_rotationCenter = { -1, -1 };
}

void Sprite::SetOpacity(Uint8 opacity)
{
	SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(m_texture, opacity);
}

Sprite::~Sprite()
{
	AssetManager& am = AssetManager::Get();
	am.UnsetTexture(m_filePath);

	m_texture = nullptr;
	m_filePath = nullptr;
}

void Sprite::Draw(SDL_Renderer* renderer)
{
	SDL_Rect dst{ m_pos.GetX(), m_pos.GetY(), m_frameWidth, m_frameHeight};

	SDL_Point* center = nullptr;
	SDL_Point autoCenter;

	if (m_rotationCenter.x >= 0)
	{
		center = &m_rotationCenter;
	}
	else
	{
		autoCenter = { m_frameWidth / 2, m_frameHeight / 2 };
		center = &autoCenter;
	}

	SDL_RenderCopyEx(renderer, m_texture, nullptr, &dst, m_angle, center, m_flip);
}
