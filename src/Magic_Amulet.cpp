#include"../include/Magic_Amulet.h"


    
Magic_Amulet::Magic_Amulet(string name,int value):Item(name,value){}
void Magic_Amulet::use_Item(Character*character)
{
    character->improve_defense(m_value);
    printslow("Your hero defense improve in power of:" + std::to_string(m_value) + "\n");
}
string Magic_Amulet::getName()const 
{
        return m_name;
}

