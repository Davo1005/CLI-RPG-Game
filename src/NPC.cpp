#include "../include/NPC.h"
#include "../include/Utils.h"

#include<iostream>
extern Hero* hero;
NPC::NPC(string name, QuestManager* questmanager) : Character(name, 0, 0, 0), m_questmanager(questmanager) {}

void NPC::displayStats() const {
  printslow(m_name + "\n");
}

void NPC::interact(Character* target) {
  printslow("Your hero interacts with: " + target->get_name() + "\n");
}

void NPC::takeDamage(int damage) {
  printslow("You can't attack me\n");
}

string NPC::getDialogue() const {
  string dialogue = "I'm a villager, can you help me?\nI have a quest for you.";
  printslow(dialogue + "\n");

  Quest* quest = m_questmanager->get_Quest();
  if (quest) {
    printslow(quest->get_description() + "\n");

    m_questmanager->assign_quest(hero, quest);
  }

  return dialogue;
}
