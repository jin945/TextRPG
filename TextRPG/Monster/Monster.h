#pragma once
#include <string>
class Monster
{
public:
	virtual std::string getName() const = 0;
	virtual void takeDamage(int damage) = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	//virtual item* dropItem() const = 0; 추후 구현

	virtual ~Monster()
	{
	}
};