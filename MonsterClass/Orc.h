#pragma once
#include "monster.h"
#include <string>

class Orc : public Monster {
private:
    std::string name;
    int health;
    int attack;

    int getRandomInRange(int min, int max);

public:
    Orc(int level);

    std::string getName() const override;
    void takeDamage(int damage) override;
    int getHealth() const override;
    int getAttack() const override;

};
