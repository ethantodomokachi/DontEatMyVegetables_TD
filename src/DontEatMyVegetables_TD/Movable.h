// Created by Mermin Kylian on 16/01/2025

#pragma once
#include "Vector2f.h"

class Movable
{
protected:
	Vector2f m_dir;
	float m_speed;

public:
	Movable(float speed, Vector2f dir);
	virtual void SetDirection(Vector2f dir);
	virtual void SetSpeed(float speed);
	virtual void Move(float deltaTime) = 0;
};

