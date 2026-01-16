// Created by Mermin Kylian on 16/01/2025

#pragma once
#include "Vector2f.h"

class Transformable
{
protected:
	Vector2f m_pos;

public:
	Transformable(Vector2f position);

	void SetPosition(Vector2f position);
	Vector2f GetPosition() { return m_pos; }
};

