#include "Orc.h"
#include <random>

int Orc::getRandomInRange(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

Orc::Orc(int characterLevel)
    : name("Orc"),
    health(getRandomInRange(characterLevel * 20, characterLevel * 30)),
    attack(getRandomInRange(characterLevel * 5, characterLevel * 10))
{
}

std::string Orc::getName() const
{
    return name;
}

int Orc::getHealth() const
{
    return health;
}

int Orc::getAttack() const
{
    return attack;
}

void Orc::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}



