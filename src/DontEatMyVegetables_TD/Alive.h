// Created by Mermin Kylian on 16/01/2025

#pragma once

class Alive
{
protected:
	float m_maxHealth;
	float m_health;

public:
	Alive(float maxHealth);
	virtual float GetMaxHealth() { return m_maxHealth; }
	virtual float GetHealth() { return m_health; }

	virtual void TakeDamage(float amount);
	virtual bool IsAlive();
};

