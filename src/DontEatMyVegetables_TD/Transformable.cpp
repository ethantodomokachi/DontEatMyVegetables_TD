// Created by Mermin Kylian on 16/01/2025

#include "Transformable.h"

Transformable::Transformable(Vector2f position) : m_pos(position)
{
}

void Transformable::SetPosition(Vector2f position)
{
	m_pos = position;
}
