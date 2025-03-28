#include "../include/NPC.h"

#include<iostream>
extern Hero* hero;
    NPC::NPC(string name,QuestManager * questmanager):Character(name,0,0,0), m_questmanager(questmanager){}
    void NPC::displayStats()const{
      cout<< m_name<<endl;
    }
    
    void NPC::interact(Character* target){
      cout<<"Your hero interact with:"<<target->get_name()<<endl;
    }
    
    void NPC::takeDamage(int damage)    {
      cout<<"You cant attack me"<<endl;
    }
    string NPC::getDialogue() const {
        string dialogue = "I'm a villager, can you help me?\nI have a quest for you.";
        cout << dialogue << endl;
    
        Quest* quest = m_questmanager->get_Quest();
        if (quest) {
            cout << quest->get_description() << endl;

            m_questmanager->assign_quest(hero, quest);
        }
    
        return dialogue;
    }


