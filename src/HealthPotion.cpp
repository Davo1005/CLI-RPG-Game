#include"../include/HealthPotion.h"
#include"../include/Item.h"

  
    HealthPotion::HealthPotion(string name,int value):Item(name,value){}
            void HealthPotion::use_Item(Character*character){
                character->recover(m_value);
                printslow("Your hero is recovered with size: ");
                printslow( to_string(m_value));
                cout << endl;
            }
            string HealthPotion::getName()const {
                return m_name;
            }

