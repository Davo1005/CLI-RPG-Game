#ifndef NPC_H
#define NPC_H
#include "../include/NPC.h"

#include<iostream>
class NPC:public Character,public Interactable{
  public:
    NPC(string name,QuestManager questmanager):Character(name,0,0,0), m_questmanager{&questmanager}{}
    void displayStats()const{
      cout<< m_name<<endl;
    }
    void attack(Character* target)override{
      cout<<"You cant attack me"<<endl;
    }
    
    void useAbility(Character* target)override{
      cout<<"You cant attack me"<<endl;
    }
    
    void interact(Character* target)override{
      cout<<"Your hero interact with:"<<target->get_name()<<endl;
    }
    
    void virtual takeDamage(int damage)override{
      cout<<"You cant attack me"<<endl;
    }

    void virtual takeDamage(int damage){
      cout<<"You cant attack me"<<endl;
    }
    void get_dialogue(Hero* hero){
      cout<<"Im a villager can you help me"<<endl;
      cout<<"I have quest for you"<<endl;
      Quest* quest=m_questmanager->get_Quest();
      quest->get_description();
      m_questmanager->assign_quest(hero,quest);
    }
  private:
    string m_name;
    QuestManager* m_questmanager;
};
#endif
