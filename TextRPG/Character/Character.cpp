#include "Character.h"

Character* Character::instance = nullptr;

Character::Character(std::string name)
{
	this->name = name;
	level = 1;
	maxHealth = 100;
	health = maxHealth;
	attack = 30;
	experience = 0;
	gold = 0;
}

Character* Character::getInstance(std::string name)
{
	if (instance == nullptr)
	{
		instance = new Character(name);
	}
	return instance;
}

void Character::displayStatus()
{
	std::cout << "------------------\n"
		<< "Character's Name: " << name << '\n'
		<< "Level: " << level << '\n'
		<< "HP: " << health << " / " << maxHealth << '\n'
		<< "Attack: " << attack << '\n'
		<< "EXP: " << experience << '\n'
		<< "Gold: " << gold << '\n'
		<< "------------------\n";
}

void Character::levelUp()
{
	// 전투시스템에서 경험치가 100이상이면 levelUP() 하므로 아래 if문 체크안함
	//if (experience >= 100)

	// 누적 경험치가 200 이상임을 고려함
	while (experience >= 100)
	{
		experience -= 100;
		++level;
	}

	std::cout << "Level Up! Current Level / Experience: "
		<< level << " / " << experience << '\n';

}

void Character::useItem(int index)
{
	if (index >= 0 && index < inventory.size())
	{
		if (inventory[index] != nullptr)
		{
			// 인벤토리 사용 후 삭제
			// TODO: 인벤토리의 아이템 사용(Item::use())

			delete inventory[index];
			inventory[index] = nullptr;
		}
		else
		{
			std::cout << "Error: There are no items in Inventory." << '\n';
		}
	}
	else
	{
		std::cout << "Error: Invalid item index." << '\n';
	}
}

void Character::visitShop()
{
	// 도전기능: interaction with Shop
}
