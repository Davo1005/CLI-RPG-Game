#ifndef SWORD
#define SWORD
#include"Item.h"

class Sword:public Item{
    public:
        Sword(string name,int value):Item(name,value){}
        void use_Item(Character * character)override{
            cout<<"Your hero attack improve in power of:"<<m_value<<endl;
        }
        string getName()const override{
            return m_name;
        }
};

#endif