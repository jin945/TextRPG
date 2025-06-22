#pragma once
#include "Monster.h"
#include <memory>
//몬스터 기능 확장용 데코레이터
class MonsterDecorator : public Monster
{
protected:
	std::unique_ptr<Monster> monster;

public:

	MonsterDecorator(std::unique_ptr<Monster> m)
		: monster(std::move(m)) {}

	std::string getName() const override
	{
		return monster->getName();
	}

	int getHealth() const override
	{
		return monster->getHealth();
	}

	int getAttack() const override
	{
		return monster->getAttack();
	}

	void takeDamage(int damage) override
	{
		monster->takeDamage(damage);
	}

	
	virtual ~MonsterDecorator() = default;
};
