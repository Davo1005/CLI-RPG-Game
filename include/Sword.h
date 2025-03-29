#ifndef SWORD
#define SWORD
#include"Item.h"
#include "Utils.h"

class Sword:public Item{
    public:
        Sword(string name,int value);
        void use_Item(Character * character);
        string getName()const ;
};


#endif