#include "Troll.h"
#include <random>

int Troll::getRandomInRange(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

Troll:: Troll(int characterLevel)
    : name("Troll"),
    health(getRandomInRange(characterLevel * 20, characterLevel * 30)),
    attack(getRandomInRange(characterLevel * 5, characterLevel * 10))
{
}

std::string Troll::getName() const
{
    return name;
}

int Troll::getHealth() const
{
    return health;
}

int Troll::getAttack() const
{
    return attack;
}

void Troll::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}



