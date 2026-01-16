// Created by Mermin Kylian on 16/01/2025

#include "Alive.h"

Alive::Alive(float maxHealth)
{
	m_maxHealth = maxHealth;
	m_health = m_maxHealth;
}

void Alive::TakeDamage(float amount)
{
	m_health -= amount;
}

bool Alive::IsAlive()
{
	if (m_health <= 0)
		return false;

	return true;
}
