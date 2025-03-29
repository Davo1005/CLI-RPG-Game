#ifndef MAGICAMULET
#define MAGICAMULET
#include"Item.h"
#include"Utils.h"
    class Magic_Amulet:public Item{
        public:
            Magic_Amulet(string name,int value);
            void use_Item(Character*character);
            string getName()const ;
    };
#endif
