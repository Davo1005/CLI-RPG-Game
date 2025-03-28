#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
using namespace std;

class Character{
  protected:
    string m_name;
    int m_health; 
    int m_attackPower;
    int m_defense;
  public:
    Character(string name,int health,int attackPower,int defense):m_name(name),m_health(health),m_attackPower(attackPower),m_defense(defense){}
    void virtual displayStats()const=0;
    void virtual takeDamage(int damage)=0;
    int get_helth()const{
      return m_health;
    }

    virtual ~Character()=default;
    string get_name(){
      return m_name;
    }
    virtual void recover(int value){
      m_health+=value;
    }
    virtual void improve_defense(int value){
      m_defense+=value;
    }
};
#endif 