#include "Goblin.h"
#include <random>

int Goblin::getRandomInRange(int min, int max) 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

Goblin::Goblin(int characterLevel)
    : name("Goblin"),
    health(getRandomInRange(characterLevel * 20, characterLevel * 30)),
    attack(getRandomInRange(characterLevel * 5, characterLevel * 10))
{}

std::string Goblin::getName() const 
{
    return name;
}

int Goblin::getHealth() const 
{
    return health;
}

int Goblin::getAttack() const 
{
    return attack;
}

void Goblin::takeDamage(int damage) 
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}


   
