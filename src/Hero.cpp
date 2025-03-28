#include"../include/Hero.h"
#include "../include/Utils.h"
Hero::Hero(string name,Herotype herotype):Character(name,100,25,10){
    m_herotype=herotype;
    m_level=1;
    m_XP=0;  
}

void Hero::recover(int value){
    m_health+=value;
    cout<<"Your hero is recovered in with size:"<<value<<endl;
}
void Hero::improve_defense(int value){
    m_defense+=value;
    cout<<"Your hero defense improve in power of:"<<value<<endl;
}
string Hero::getName()const{
    return m_name;
}
void Hero::attack(Character*target){
    if(target==nullptr){
        return;
    }
    target->takeDamage(m_attackPower);
    cout<<"Your hero attack on"<<target->get_name()<<"In attackpower:"<<m_attackPower<<endl;
}
void Hero::takeDamage(int damage){
    damage-=m_defense;
    if(damage>0){
        m_health-=damage;
          if(m_health<0)
          {
            cout<<"Your hero is dead";
          }
    }   
}

void Hero::addItem(Item*inventory){
  m_inventory.push_back(inventory);
}
  void Hero::useItem(int index) {
    if (index >= 0 && index < m_inventory.size()) {
      cout<<"You use"<<m_inventory[index]->getName()<<endl;
        m_inventory[index]->use_Item(this); 
        delete[]m_inventory[index];
        m_inventory.erase(m_inventory.begin()+index);
        cout<<"Your item was used"<<endl; 
    }
        std::cout << "Invalid item index.\n";
    }
    void Hero::gainXP(int xp){
      cout<<"Your hero gained "<<xp<<"xp"<<endl;
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
          cout<<"Your level is up"<<m_level<<endl;
         }
    }
  
void Hero::displayStats()const{
    cout<<"Hero:"<<m_name<<endl;
    cout<<"Your hero is:";
    print_herotype(m_herotype);
    cout<<endl;
    cout<<"Health:"<<m_health<<endl;
    cout<<"AttackPower:"<<m_attackPower<<endl;
    cout<<"Defense:"<<m_defense<<endl;
    cout<<"Level:"<<m_level<<endl;
    cout<<"XP:"<<m_XP;
}

    void Hero::useAbility(Character*target){
      if(target==nullptr){
        cout<<"There is no such target"<<endl;
        return;
      }
      if(m_herotype==Herotype::Warrior){
        cout<<"You use Power Strike on:"<< target->get_name()<<endl;
        target->takeDamage(20);
      }
      if(m_herotype==Herotype::Mage){
        cout<<"You use Fireball on:"<<target->get_name()<<endl;
        target->takeDamage(20); 
      }
      if(m_herotype==Herotype::Rogue){
        cout<<"You use Stealth Attack on:"<<target->get_name()<<endl;
        target->takeDamage(20);
      }
    }
    void Hero::interact(Character*target){
      cout<<"Your hero interact with:"<<target->get_name()<<endl;
    }
    string Hero::getDialogue()const {
      return "Hello I am hero";
    }
    void Hero::printItem()const{
      for(int i=0;i<m_inventory.size();i++){
        cout<<m_inventory[i]->getName()<<endl;
      }


    }
    Hero::~Hero(){
     for(int i=0;i<m_inventory.size();i++){
      delete []m_inventory[i];
     }
     m_inventory.clear();
    }