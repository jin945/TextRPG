#pragma once
#include <iostream>
#include <string>
#include <vector>

class Item;
class Character
{
private:

	static Character* instance;

	std::string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;
	std::vector<Item*> inventory;

public:

	Character(std::string name);

	static Character* getInstance(std::string name = "");

	void displayStatus();
	void levelUp();
	void useItem(int index);
	void visitShop();
};