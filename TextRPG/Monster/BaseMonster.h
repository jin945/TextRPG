#pragma once
#include "Monster.h"
#include <random>
//몬스터 기본 기능 구현
class BaseMonster : public Monster
{
private:
	int health;
	int attack;
	std::string name;

	int getRandomInRange(int min, int max) const
	{
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(min, max);
		return dist(gen);
	}

public:
	BaseMonster(int level, std::string name)
		: health(getRandomInRange(level * 20, level * 30)),
		attack(getRandomInRange(level * 5, level * 10)),
		name(name)
	{}

	std::string getName() const override
	{
		return name;
	}

	void takeDamage(int damage) override//damage = character->getAttack()
	{
		health -= damage;
		if (health < 0) health = 0;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}
};
