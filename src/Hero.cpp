#include"../include/Hero.h"
#include "../include/Utils.h"
Hero::Hero(string name,Herotype herotype):Character(name,100,25,10){
  m_herotype=herotype;
  m_level=1;
  m_XP=0;  
}

void Hero::recover(int value){
  m_health+=value;
  printslow("Your hero is recovered in with size:" + std::to_string(value) + "\n");
}
void Hero::improve_defense(int value){
  m_defense+=value;
  printslow("Your hero defense improve in power of:" + std::to_string(value) + "\n");
}
string Hero::getName()const{
  return m_name;
}
void Hero::attack(Character*target){
  if(target==nullptr){
    return;
  }
  target->takeDamage(m_attackPower);
  printslow("Your hero attack on " + target->get_name() + ". In attack power:" + std::to_string(m_attackPower) + "\n");
}
void Hero::takeDamage(int damage){
  damage-=m_defense;
  if(damage>0){
    m_health-=damage;
    if(m_health<0)
    {
      printslow("Your hero is dead\n");
    }
  }   
}

void Hero::addItem(Item*inventory){
  m_inventory.push_back(inventory);
}
void Hero::useItem(int index) {
  if (index >= 0 && index < m_inventory.size()) {
    printslow("You use " + m_inventory[index]->getName() + "\n");
    m_inventory[index]->use_Item(this); 
    delete[]m_inventory[index];
    m_inventory.erase(m_inventory.begin()+index);
    printslow("Your item was used\n"); 
  }
  else
  {
    printslow("Invalid item index.\n");
  }
}
void Hero::gainXP(int xp){
  printslow("Your hero gained " + std::to_string(xp) + " xp\n");
  m_XP+=xp;
  if(m_XP>xptolevelup){
    levelup();
  }
}
int Hero::getlevel(){
  return m_level;
}
void Hero::levelup(){
  while(m_XP>=xptolevelup){
    m_XP-=xptolevelup;
    m_level++;
    m_health+=25;
    m_defense+=15;
    m_attackPower+=25;
    printslow("Your level is up " + std::to_string(m_level) + "\n");
  }
}

void Hero::displayStats()const{
  printslow("Hero: " + m_name + "\n");
  printslow("Your hero is: ");
  print_herotype(m_herotype);
  printslow("\n");
  printslow("Health: " + std::to_string(m_health) + "\n");
  printslow("AttackPower: " + std::to_string(m_attackPower) + "\n");
  printslow("Defense: " + std::to_string(m_defense) + "\n");
  printslow("Level: " + std::to_string(m_level) + "\n");
  printslow("XP: " + std::to_string(m_XP) + "\n");
}

void Hero::useAbility(Character*target){
  if(target==nullptr){
    printslow("There is no such target\n");
    return;
  }
  if(m_herotype==Herotype::Warrior){
    printslow("You use Power Strike on: " + target->get_name() + "\n");
    target->takeDamage(20);
  }
  if(m_herotype==Herotype::Mage){
    printslow("You use Fireball on: " + target->get_name() + "\n");
    target->takeDamage(20); 
  }
  if(m_herotype==Herotype::Rogue){
    printslow("You use Stealth Attack on: " + target->get_name() + "\n");
    target->takeDamage(20);
  }
}
void Hero::interact(Character*target){
  printslow("Your hero interact with: " + target->get_name() + "\n");
}
string Hero::getDialogue()const {
  return "Hello I am hero";
}
void Hero::printItem()const{
  for(int i=0;i<m_inventory.size();i++){
    printslow(m_inventory[i]->getName() + "\n");
  }
}

Hero::~Hero(){
  for(int i=0;i<m_inventory.size();i++){
    delete []m_inventory[i];
  }
  m_inventory.clear();
}
