#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include<random>
void GameManager :: effectItem(enum ItemNumber)
{

}
void GameManager :: battle(Character* player, std::unique_ptr<Monster> monster)
{
	std::string monsterName = monster->getName();
	std::string characterName = player->getName();
	

	std::cout<<"전투 시작! "<<monsterName<<" 이(가) 나타났다!\n";
	std::cout<<monsterName<<"'s HP: "<<monster->getHealth()<<"\n";
	std::cout<<monsterName<<"'s Attack: "<<monster->getAttack()<<"\n\n";
	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{
	
		// 캐릭터 턴 - 50% 확률로 공격력 포션 자동 사용
		if (rand()%100<50)
		{
			for (int i = 0; i<player->getInventorySize(); ++i)
			{
				if (player->getItemName(i)=="ATK+20 포션")
				{
					player->useItem(i);
					break;
				}
			}
		}
		std::cout<<">> "<<characterName<<"의 공격!\n";
		monster->takeDamage(player->getAttack());
		std::cout<<monsterName<<"'s HP: "<<monster->getHealth()<<"\n\n";


		//몬스터 처치시
		if (monster->getHealth()<=0)
		{
			std::cout<<monsterName<<" 을(를) 처치했다!\n";
			//30% 확률로 체력 회복 아이템 드랍
			if (rand()%100<30)  
			{
				std::cout<<">> "<<monsterName<<"이(가) HP+50 포션을 드랍!\n";
				player->addItem(new HealthPotion());
			}


			break;
		}

		// 몬스터 턴
		std::cout<<">> "<<monsterName<<"의 공격!\n";
		player->takeDamage(monster->getAttack());
		std::cout<<characterName<<"'s HP: "<<player->getHealth() <<"\n\n";

		if (player->getHealth()<=0)
		{
			std::cout<<characterName<<"이(가) 쓰러졌습니다. 게임 종료.\n";
			exit(0); 
		}
		//캐릭터 체력이 50% 이하일 때 자동으로 HP 포션 사용
		if (player->getHealth()<=player->getMaxHealth()/2)
		{
			for (int i = 0; i<player->getInventorySize(); ++i)
			{
				if (player->getItemName(i)=="HP+50 포션")
				{
					player->useItem(i);
					break;
				}
			}
		}
	}

	std::cout<<"전투 종료.\n";
	
	if(player->getLevel()==10)
	{ 
		std::cout<<"Game Clear!\n";
		exit(0);
	}

	//보상 획득
	std::cout<<">> "<<characterName<<"이(가) "<<monster->getExpReward()<<" 경험치를 얻었습니다!\n";
	player->addExperience(monster->getExpReward());
		
	int gold = monster->getGoldReward();
	std::cout<<">> "<<characterName<<"이(가) "<<gold<<" 골드를 얻었습니다!\n\n";
	player->addGold(gold);
		

	//상점 방문
	player->visitShop();
}