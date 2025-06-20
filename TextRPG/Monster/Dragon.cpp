#include "Dragon.h"
#include <random>

int Dragon::getRandomInRange(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

Dragon::Dragon(int characterLevel)
    : name("Dragon"),
    health(static_cast<int>(getRandomInRange(characterLevel * 20, characterLevel * 30) * 1.5)),
    attack(static_cast<int>(getRandomInRange(characterLevel * 5, characterLevel * 10) * 1.5))
{
}

std::string Dragon::getName() const
{
    return name;
}

int Dragon::getHealth() const
{
    return health;
}

int Dragon::getAttack() const
{
    return attack;
}

void Dragon::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}



