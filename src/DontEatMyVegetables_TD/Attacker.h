// Created by Mermin Kylian on 16/01/2025

#pragma once

class Alive;

class Attacker
{
public:
	virtual void Attack(Alive* target) = 0;
};