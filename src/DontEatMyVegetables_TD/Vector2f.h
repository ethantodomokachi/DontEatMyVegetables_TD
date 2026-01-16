// Created by Mermin Kylian on 16/01/2025

#pragma once

class Vector2f
{
	float m_x;
	float m_y;

public:
	
	Vector2f(float x, float  y);
	~Vector2f() {}

	void Set(float x, float y);

	float GetDistance(Vector2f vect);
	Vector2f ComputeDirection(Vector2f vect);

	Vector2f Normalize();
	float GetMagnitude();

	Vector2f operator-(const Vector2f& right);
	Vector2f operator+(const Vector2f& right);
	Vector2f operator*(float right);
	
	float GetX() { return m_x; }
	float GetY() { return m_y; }
};