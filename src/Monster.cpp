#include"../include/Monster.h"
#include"../include/Utils.h"
Monster::Monster(string name,Monstertype type):Character(name,50,25,10){
    m_type=type;
}
void Monster::displayStats() const{
    cout<<"Monster:"<<m_name<<endl;
    cout<<"Monster is:";
    print_monstertype(m_type);
    cout<<endl;
    cout<<"Health:"<<m_health<<endl;
    cout<<"Attack Power:"<<m_attackPower<<endl;
    cout<<"Defense:"<<m_defense<<endl;
}
void  Monster::takeDamage(int damage){
    damage-=m_defense;
    if(damage>0){
        m_health-=damage;
          if(m_health<0){
            cout<<"monster is dead";
          }
    }   
 }   
void Monster::attack(Character* target){
    if(target==nullptr){
        return;
    }
    target->takeDamage(m_attackPower);
    cout<<"Mnster attack on "<<target->get_name()<<". In attack power:"<<m_attackPower<<endl;     
}
void Monster::useAbility(Character*target){
    if(m_type==Monstertype::Goblin){
        cout<<"Goblin use poison attack on"<<target->get_name()<<endl;
        cout<<"Your hero was damaged in 25 health"<<endl;
        target->takeDamage(25);
    }
    if (m_type==Monstertype::Dragon){
        cout<<"Dragon use fire attack on"<<target->get_name()<<endl;
        cout<<"your hero was damaged in 25 health"<<endl;
        target->takeDamage(25);   
    }
    if(m_type==Monstertype::Troll){
        cout<<"Troll use area attack on"<<target->get_name()<<endl;
        cout<<"Your hero was damaged in 25 health"<<endl;
        target->takeDamage(25);
    }
}
 