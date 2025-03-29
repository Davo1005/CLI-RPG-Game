#include"../include/Monster.h"
#include"../include/Utils.h"

extern Hero* hero;
Monster::Monster(string name,Monstertype type):Character(name,50,25,10){
    m_type=type;
}
void Monster::displayStats() const{
    printslow("Monster:" + m_name + "\n");
    printslow("Monster is:");
    print_monstertype(m_type);
    printslow("\n");
    printslow("Health:" + to_string(m_health) + "\n");
    printslow("Attack Power:" + to_string(m_attackPower) + "\n");
    printslow("Defense:" + to_string(m_defense) + "\n");
}
void  Monster::takeDamage(int damage){
    damage -= m_defense;
    if(damage > 0){
        m_health -= damage;
        if(m_health < 0){
            printslow("Monster is dead ");
        }
    }   
}   
void Monster::attack(Character* target){
    if(target == nullptr){
        return;
    }
    target->takeDamage(m_attackPower);
    printslow("Monster attack on " + target->get_name() + ". In attack power:" + to_string(m_attackPower) + "\n");     
}
void Monster::useAbility(Character* target){
    if(m_type == Monstertype::Goblin){
        printslow("Goblin use poison attack on " + target->get_name() + "\n");
        printslow("Your hero was damaged in 25 health\n");
        target->takeDamage(25);
    }
    if(m_type == Monstertype::Dragon){
        printslow("Dragon use fire attack on " + target->get_name() + "\n");
        printslow("Your hero was damaged in 25 health\n");
        target->takeDamage(25);   
    }
    if(m_type == Monstertype::Troll){
        printslow("Troll use area attack on " + target->get_name() + "\n");
        printslow("Your hero was damaged in 25 health\n");
        target->takeDamage(25);
    }
}
