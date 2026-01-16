// Created by Mermin Kylian on 16/01/2025

#include <SDL_image.h>
#include <iostream>
#include "AssetManager.h"

AssetManager& AssetManager::Get()
{
    static AssetManager Instance;
    return Instance;
}

TextureData* AssetManager::LoadTexture(const std::string& filePath, SDL_Renderer* renderer)
{
    auto it = m_textures.find(filePath);
    if (it != m_textures.end())
    {
        it->second->count++;
        return it->second;
    }

    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath.c_str());
    if (!texture)
        return nullptr;

    int width = 0;
    int height = 0;

    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    TextureData* tData = new TextureData();
    tData->texture = texture;
    tData->width = width;
    tData->height = height;
    tData->count = 1;

    m_textures[filePath] = tData;

    return tData;
}

void AssetManager::UnsetTexture(const std::string& filePath)
{
    auto it = m_textures.find(filePath);
    if (it != m_textures.end())
    {
        it->second->count--;
    }

    if (it->second->count <= 0)
    {
        SDL_DestroyTexture(it->second->texture);
        delete it->second;

        m_textures.erase(it);
    }
}