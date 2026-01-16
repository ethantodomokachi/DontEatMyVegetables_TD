#pragma once
#include "Drawable.h"
#include "Transformable.h"

class Sprite : public Drawable, public Transformable
{
protected:
    SDL_Texture* m_texture;
    const char* m_filePath;

    int m_frameWidth;
    int m_frameHeight;

    float m_angle;
    SDL_Point m_rotationCenter;
    SDL_RendererFlip m_flip;

public:
    Sprite(SDL_Renderer* r, const char* fp);
    virtual ~Sprite();

    virtual void SetSpriteSheet(int frameWidth, int frameHeight);

    SDL_Rect GetFrame(int indexX, int indexY) const;

    void Resize(int width, int height);

    void SetRotation(float angle);
    void SetFlip(SDL_RendererFlip flip);
    void SetRotationCenter(int x, int y);
    void ResetTransform();

    void SetOpacity(Uint8 opacity);

    void Draw(SDL_Renderer* renderer) override;

    const char* GetFilePath() { return m_filePath; }
};

