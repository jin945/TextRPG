#pragma once
#include "MonsterDecorator.h"
#include <string>
#include <cmath> 
//보스 몬스터의 이름 뒤에 "King" 추가, 스텟 1.5배 증가
class BossDecorator : public MonsterDecorator
{
public:
	BossDecorator(std::unique_ptr<Monster> m)
		: MonsterDecorator(std::move(m))
	{}

	std::string getName() const override
	{
		return monster->getName() + " King";
	}

	int getHealth() const override
	{
		return static_cast<int>(std::round(monster->getHealth() * 1.5));
	}

	int getAttack() const override
	{
		return static_cast<int>(std::round(monster->getAttack() * 1.5));
	}
};
