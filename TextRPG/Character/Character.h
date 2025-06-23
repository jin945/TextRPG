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
	int maxHealth;
	int health;
	int attack;
	int experience;
	int gold;
	std::vector<Item*> inventory;

public:

	Character(std::string name);

	static Character* getInstance(std::string name = "");

	void displayStatus()const;
	void levelUp();
	void useItem(int index);
	void visitShop();

	int getHealth() const;
	int getMaxHealth() const;
	int getAttack() const;
	int getLevel() const;
	std::string getName() const;

	void takeDamage(int damage);

	void addExperience(int exp);
	void addGold(int gol);
}; 