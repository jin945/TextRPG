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
	

	std::cout<<"���� ����! "<<monsterName<<" ��(��) ��Ÿ����!\n";
	std::cout<<monsterName<<"'s HP: "<<monster->getHealth()<<"\n";
	std::cout<<monsterName<<"'s Attack: "<<monster->getAttack()<<"\n\n";
	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{
	
		// ĳ���� �� - 50% Ȯ���� ���ݷ� ���� �ڵ� ���
		if (rand()%100<50)
		{
			for (int i = 0; i<player->getInventorySize(); ++i)
			{
				if (player->getItemName(i)=="ATK+20 ����")
				{
					player->useItem(i);
					break;
				}
			}
		}
		std::cout<<">> "<<characterName<<"�� ����!\n";
		monster->takeDamage(player->getAttack());
		std::cout<<monsterName<<"'s HP: "<<monster->getHealth()<<"\n\n";


		//���� óġ��
		if (monster->getHealth()<=0)
		{
			std::cout<<monsterName<<" ��(��) óġ�ߴ�!\n";
			//30% Ȯ���� ü�� ȸ�� ������ ���
			if (rand()%100<30)  
			{
				std::cout<<">> "<<monsterName<<"��(��) HP+50 ������ ���!\n";
				player->addItem(new HealthPotion());
			}


			break;
		}

		// ���� ��
		std::cout<<">> "<<monsterName<<"�� ����!\n";
		player->takeDamage(monster->getAttack());
		std::cout<<characterName<<"'s HP: "<<player->getHealth() <<"\n\n";

		if (player->getHealth()<=0)
		{
			std::cout<<characterName<<"��(��) ���������ϴ�. ���� ����.\n";
			exit(0); 
		}
		//ĳ���� ü���� 50% ������ �� �ڵ����� HP ���� ���
		if (player->getHealth()<=player->getMaxHealth()/2)
		{
			for (int i = 0; i<player->getInventorySize(); ++i)
			{
				if (player->getItemName(i)=="HP+50 ����")
				{
					player->useItem(i);
					break;
				}
			}
		}
	}

	std::cout<<"���� ����.\n";
	
	if(player->getLevel()==10)
	{ 
		std::cout<<"Game Clear!\n";
		exit(0);
	}

	//���� ȹ��
	std::cout<<">> "<<characterName<<"��(��) "<<monster->getExpReward()<<" ����ġ�� ������ϴ�!\n";
	player->addExperience(monster->getExpReward());
		
	int gold = monster->getGoldReward();
	std::cout<<">> "<<characterName<<"��(��) "<<gold<<" ��带 ������ϴ�!\n\n";
	player->addGold(gold);
		

	//���� �湮
	player->visitShop();
}