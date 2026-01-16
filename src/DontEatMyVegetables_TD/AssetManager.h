// Created by Mermin Kylian on 16/01/2025

#pragma once
#include <map>
#include <string>
#include <SDL.h>

struct TextureData
{
	SDL_Texture* texture;
	int width;
	int height;
	int count;
};

class AssetManager
{
public:
	static AssetManager& Get();
	TextureData* LoadTexture(const std::string& filePath, SDL_Renderer* renderer);

	void UnsetTexture(const std::string& filePath);

private:
	AssetManager() {}
	std::map<std::string, TextureData*> m_textures;
};

