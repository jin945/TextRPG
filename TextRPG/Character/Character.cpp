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

void Character::displayStatus() const
{
	std::cout << "-----------------------\n"
		<< "Character's Name: " << name << '\n'
		<< "Level: " << level << '\n'
		<< "HP: " << health << " / " << maxHealth << '\n'
		<< "Attack: " << attack << '\n'
		<< "EXP: " << experience << '\n'
		<< "Gold: " << gold << '\n'
		<< "-----------------------\n";
}

void Character::levelUp()
{
	while (experience>=100)
	{
		if (level==10)
		{
			std::cout<<"Maximum level reached! (Level 10)!\n";
			experience = 0;
			break;
		}

		experience -= 100;
		++level;

		maxHealth += (level * 20);
		health = maxHealth;
		attack += (level * 5);

		std::cout<<"Level Up! Current Level / Experience: "
			<<level<<"Lv / "<<experience<<'\n';
	}
}


void Character::takeDamage(int damage)
{
	health = std::max(0, health-damage);
}

int Character::getAttack() const
{
	return attack;
}

int Character::getHealth() const
{
	return health;
}

int Character::getMaxHealth() const
{
	return maxHealth;
}

int Character::getLevel() const
{
	return level;
}

std::string Character::getName() const
{
	return name;
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

void Character::addExperience(int exp) 
{
	experience += exp; 
	levelUp();
}
void Character :: addGold(int gol) 
{ 
	gold += gol;
}

void Character::visitShop()
{
	int choice = 0;
	std::cout<<"상점을 이용하시겠습니까?\n";
	std::cout<<"1. 예\n2. 아니오\n";

	while (true)
	{
		std::cin>>choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout<<"잘못된 입력입니다. 숫자로 입력해주세요.\n> ";
			continue;
		}

		if (choice==1)
		{
			std::cout<<"상점에 오신 것을 환영합니다!\n";
			break; // 상점 입장
		}
		else if (choice==2)
		{
			std::cout<<"상점을 이용하지 않습니다.\n";
			return; // 함수 종료
		}
		else
		{
			std::cout<<"잘못된 선택입니다. 다시 선택해주세요.\n> ";
		}
	}
	//상점 구현
	std::cout<<"상점 기능은 아직 구현되지 않았습니다.\n";
}
