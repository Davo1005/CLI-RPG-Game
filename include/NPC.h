#ifndef NPC_H
#define NPC_H
#include"Character.h"
#include"QuestManager.h"
#include"Interactable.h"
#include"Character.h"
#include<iostream>
class NPC:public Character,public Interactable{
  public:
    NPC(string name,QuestManager questmanager);
    void displayStats()const;
    void virtual takeDamage(int damage);
    void get_dialogue(Hero* hero);
  private:
    string m_name;
    QuestManager* m_questmanager;
};
#endif
