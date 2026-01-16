// Created by Mermin Kylian on 16/01/2025

#include "Movable.h"

Movable::Movable(float speed, Vector2f dir) : m_dir(dir.Normalize())
{
    m_speed = speed;
}

void Movable::SetDirection(Vector2f dir)
{
    m_dir = dir.Normalize();
}

void Movable::SetSpeed(float speed)
{
    m_speed = speed;
}