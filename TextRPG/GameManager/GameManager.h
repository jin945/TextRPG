#pragma once
#include "Character.h"
#include "Monster.h"
class GameManager
{
public:
	void effectItem(enum ItemNumber);
	void battle(Character* player, std::unique_ptr<Monster> monster);//ĳ���ʹ� ��� ����, ���ʹ� ���� �� �Ҹ�
};

