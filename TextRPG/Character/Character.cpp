#include "Character.h"
#include "Item.h"
Character* Character::instance = nullptr;

Character::Character(std::string name)
{
	this->name = name;
	level = 1;
	maxHealth = 100;
	health = maxHealth;
	attack = 30;
	experience = 0;
	gold =330;
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
	std::cout<<"[Inventory]\n";
	if (inventory.empty()) {
		std::cout<<"Empty\n";
	}
	else {
		for (int i = 0; i<inventory.size(); ++i)
		{
			if (inventory[i]) {
				std::cout<<" "<<i+1<<". "<<inventory[i]->getName()<<'\n';
			}
		}
	}
	std::cout<<"-----------------------\n";
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
			inventory[index]->use(this);
			delete inventory[index];
			inventory[index] = nullptr;
			inventory.erase(std::remove(inventory.begin(), inventory.end(), nullptr), inventory.end());
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

void Character::shopMenu()
{
	int choice = 0;
	std::cout<<"상점 메뉴:\n";
	std::cout<<"1. 아이템 구매\n2. 아이템 판매\n3. 상점 나가기\n";
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
		switch (choice)
		{
		case 1:
			int buyChoice;
			std::cout<<"1.HP+50 포션(50gold)\n";
			std::cout<<"2.ATK+20 포션(100gold)\n";
			std::cin>>buyChoice;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout<<"잘못된 입력입니다.\n> ";
				continue;
			}
			if (buyChoice==1)
			{
				if (gold>=50)
				{
					gold -= 50;
					inventory.push_back(new HealthPotion());
					std::cout<<"HP 포션 구매 완료!\n";
				}
				else
				{
					std::cout<<"골드가 부족합니다.\n";
				}
			}
			else if (buyChoice==2)
			{
				if (gold>=100)
				{
					gold -= 100;
					inventory.push_back(new AttackBoost());
					std::cout<<"ATK 포션 구매 완료!\n";
				}
				else
				{
					std::cout<<"골드가 부족합니다.\n";
				}
			}
			break;
		case 2:
			if (inventory.empty()) {
				std::cout<<"판매할 아이템이 없습니다.\n";
				break;
			}

			std::cout<<"[보유 아이템 목록]\n";
			for (int i = 0; i<inventory.size(); ++i) {
				if (inventory[i])
				{
					std::cout<<i+1<<". "<<inventory[i]->getName()<<" (판매가: "<<inventory[i]->getSellPrice()<<" gold)\n";
				}
			}

			int sellIndex;
			while (true)
			{
				std::cout<<"판매할 아이템의 번호를 입력하세요: ";
				std::cin>>sellIndex;
				sellIndex -= 1; 
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout<<"잘못된 입력입니다.\n";
					continue;
				}

				if (sellIndex<0||sellIndex>=inventory.size()||inventory[sellIndex]==nullptr)
				{
					std::cout<<"아이템이 없습니다. 다시 입력해주세요.\n";
					continue;
				}

				// 판매 처리
				int sellPrice = inventory[sellIndex]->getSellPrice();
				std::cout<<inventory[sellIndex]->getName()<<"을(를) 판매했습니다! +"<<sellPrice<<" gold 획득.\n";
				gold += sellPrice;

				delete inventory[sellIndex];
				inventory[sellIndex] = nullptr;

				// 인벤토리 정리
				inventory.erase(std::remove(inventory.begin(), inventory.end(), nullptr), inventory.end());
				break;
			}
		case 3:
			std::cout<<"상점을 나갑니다.\n";
			return;
		default:
			std::cout<<"잘못된 선택입니다.\n> ";
			continue;
			}
			break;
		}
	}

void Character:: visitShop()
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
			std::cout<<"잘못된 입력입니다.\n> ";
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
	shopMenu();
	
}
void Character::increaseHealth(int amount)
{
	health = std::min(health+amount, maxHealth); 
	std::cout << "HP+50 포션 사용! 현재 체력: " << health << '\n';
}

void Character::increaseAttack(int amount)
{
	attack += amount;
	std::cout << "ATK+20 포션 사용! 현재 공격력: " << attack << '\n';
}

void Character::addItem(Item* item)
{
	if (inventory.size() < 10) 
	{
		inventory.push_back(item);
		std::cout << "아이템이 인벤토리에 추가되었습니다.\n";
	}
	else
	{
		std::cout << "인벤토리가 가득 찼습니다.\n";
		delete item; 
	}
}
int Character::getInventorySize() const {
	return inventory.size();
}

std::string Character::getItemName(int index) const {
	if (index>=0&&index<inventory.size()&&inventory[index])
		return inventory[index]->getName();
	return "";
}