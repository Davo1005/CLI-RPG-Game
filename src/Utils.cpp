#include "../include/Utils.h"

using namespace std;

void print_monstertype(Monstertype monstertype){
    if(monstertype==Monstertype::Goblin){
        cout<<"Giblin"<<endl;
    }
    if(monstertype==Monstertype::Troll){
        cout<<"Troll"<<endl;
    } 
    if(monstertype==Monstertype::Dragon){
        cout<<"Dragon"<<endl;
    }  
} 

void print_herotype(Herotype herotype){
    if(herotype==Herotype::Warrior){
        cout<<"Warrior"<<endl;
    }
    if(herotype==Herotype::Mage){
        cout<<"Mag"<<endl;
    } 
    if(herotype==Herotype::Rogue){
        cout<<"Rogue"<<endl;
    }  
} 
