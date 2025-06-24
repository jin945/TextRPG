#pragma once
#include <string>
#include"Character.h"


class Item {
private:
	int price;
	int sellPrice;
public:
	virtual std::string getName() const = 0;
	virtual void use(Character* character) = 0;
	virtual int getPrice() const=0;
	virtual int getSellPrice() const=0;
	virtual ~Item() {}
};


class HealthPotion : public Item {
private:
	int price;
	int sellPrice;
public:
	HealthPotion();
	std::string getName() const override;
	void use(Character* character) override;
	int getPrice() const override;
	int getSellPrice() const override;

};

class AttackBoost : public Item {
private:
	int price;
	int sellPrice;
public:
	AttackBoost();
	std::string getName() const override;
	void use(Character* character) override;
	int getPrice() const override;
	int getSellPrice() const override;
};
