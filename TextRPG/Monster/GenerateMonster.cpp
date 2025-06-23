#include "GenerateMonster.h"
//���� ����
enum class MonsterType
{
	Goblin,
	Orc,
	Troll,
	Slime,
	Dragon
};

std::unique_ptr<Monster> createMonster(MonsterType type, int level)//���� ���� ����
{
	std::unique_ptr<Monster> baseMonster;

	switch (type)
	{
	case MonsterType::Goblin: baseMonster = std::make_unique<Goblin>(level); break;
	case MonsterType::Orc: baseMonster = std::make_unique<Orc>(level); break;
	case MonsterType::Troll: baseMonster = std::make_unique<Troll>(level); break;
	case MonsterType::Slime: baseMonster = std::make_unique<Slime>(level); break;
	case MonsterType::Dragon: baseMonster = std::make_unique<Dragon>(level); break;
	default: return nullptr;
	}

	if (level==10)
	{
		return std::make_unique<BossDecorator>(std::move(baseMonster));
	}

	return baseMonster;
}

std::unique_ptr<Monster> createRandomMonster(int level)//���� ���� ���� unique_ptr<Monster> monster = createRandomMonster(level)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 4);

	MonsterType randomType = static_cast<MonsterType>(dis(gen));
	return createMonster(randomType, level);
}
