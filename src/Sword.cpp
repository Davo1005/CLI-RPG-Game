#include"../include/Sword.h"
#include"../include/Item.h"
#include "../include/Utils.h"


        Sword::Sword(string name,int value):Item(name,value){}
        void Sword::use_Item(Character * character){
            printslow("Your hero attack improve in power of:" + std::to_string(m_value) + "\n");
        }
        string Sword::getName()const {
            return m_name;
        }

