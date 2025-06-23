#include "BossDecorator.h"
#include <iostream>
BossDecorator::BossDecorator(std::unique_ptr<Monster> m)
	: MonsterDecorator(std::move(m))
{
	bossHealth = static_cast<int>(std::round(monster->getHealth()*1.5));
	bossAttack = static_cast<int>(std::round(monster->getAttack()*1.5));
	std::cout<<"�ְ����� �����Ͽ� ���� ���Ͱ� ��ȯ�˴ϴ�.\n";
}

std::string BossDecorator::getName() const 
{
	return monster->getName()+" King";
}

int BossDecorator::getHealth() const 
{
	return bossHealth;
}

int BossDecorator::getAttack() const 
{
	return bossAttack;
}

void BossDecorator::takeDamage(int damage) 
{
	bossHealth = std::max(0, bossHealth-damage);
}

int BossDecorator::getExpReward() const //���� Ŭ���� �� ���� ����
{
	return 0;  
}

int BossDecorator::getGoldReward() const
{
	return 0;
}
