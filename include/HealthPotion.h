#pragma once
#include"Item.h"
#include"Hero.h"
#include"Utils.h"
    class HealthPotion:public Item{
        public:
            HealthPotion(string name,int value);
            void use_Item(Character*character);
            string getName()const;
    };

