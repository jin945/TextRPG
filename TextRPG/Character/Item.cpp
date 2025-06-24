#include "Item.h"
HealthPotion::HealthPotion():
	price(50),
	sellPrice(static_cast<int>(price*0.6))
	{}


std::string HealthPotion::getName() const {
	return "HP+50 포션";
}

void HealthPotion::use(Character* character) {
	character->increaseHealth(50);
}
int HealthPotion::getPrice() const {
	return price;
}
int HealthPotion::getSellPrice() const {
	return sellPrice;
}


AttackBoost::AttackBoost():
	price(100),
	sellPrice(static_cast<int>(price * 0.6))
{}

std::string AttackBoost::getName() const {
	return "ATK+20 포션";
}

void AttackBoost::use(Character* character) {
	character->increaseAttack(20);
}

int AttackBoost::getPrice() const {
	return price;
}

int AttackBoost::getSellPrice() const {
	return sellPrice;
}