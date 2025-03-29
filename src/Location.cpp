
#include"../include/Location.h"
#include<vector>

        Location::Location(const string& name):m_name(name){};
        void Location::addentity(Character*entity){
            entities.push_back(entity);
            printslow(entity->get_name() + " Added in location\n");
        }
        void Location:: displayLocationInfo()const{
            printslow("You are in the " + m_name + "\n");
            printslow("Characters here\n");
            for (int i=0;i<entities.size();i++){
                entities[i]->displayStats();
            }
        }
        string Location:: get_Location_name()const{
            return m_name;
        }
        vector<Character*> Location::get_entities(){
            return entities;
        }  