#include "Slime.h"
#include <random>

int Slime::getRandomInRange(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

Slime::Slime(int characterLevel)
    : name("Slime"),
    health(getRandomInRange(characterLevel * 20, characterLevel * 30)),
    attack(getRandomInRange(characterLevel * 5, characterLevel * 10))
{
}

std::string Slime::getName() const
{
    return name;
}

int Slime::getHealth() const
{
    return health;
}

int Slime::getAttack() const
{
    return attack;
}

void Slime::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}



