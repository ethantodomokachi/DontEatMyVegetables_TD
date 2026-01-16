// Created by Mermin Kylian on 16/01/2025

#include "Vector2f.h"
#include <iostream>

Vector2f::Vector2f(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Vector2f::Set(float x, float y)
{
	m_x = x;
	m_y = y;
}

float Vector2f::GetDistance(Vector2f vect)
{
	float dx = vect.GetX() - m_x;
	float dy = vect.GetY() - m_y;
	return std::sqrt(dx * dx + dy * dy);
}

Vector2f Vector2f::ComputeDirection(Vector2f vect)
{
	float dx = vect.GetX() - m_x;
	float dy = vect.GetY() - m_y;
	float length = std::sqrt(dx * dx + dy * dy);

	if (length == 0)
		return Vector2f(0, 0);

	return Vector2f(dx / length, dy / length);
}

Vector2f Vector2f::Normalize() 
{
	float d = GetMagnitude();

	if (d == 0)
		return Vector2f(0, 0);

	float x = m_x / d;
	float y = m_y / d;

	return Vector2f(x, y);
}

float Vector2f::GetMagnitude() 
{
	return std::sqrt(m_x * m_x + m_y * m_y);
}

Vector2f Vector2f::operator-(const Vector2f& right) 
{
	return Vector2f(m_x - right.m_x, m_y - right.m_y);
}

Vector2f Vector2f::operator+(const Vector2f& right) 
{
	return Vector2f(m_x + right.m_x, m_y + right.m_y);
}

Vector2f Vector2f::operator*(float right) 
{
	return Vector2f(m_x * right, m_y * right);
}