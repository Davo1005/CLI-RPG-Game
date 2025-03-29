#ifndef LOCATION_H
#define LOCATION_H
#include"Character.h"
#include "Utils.h"
#include<vector>
class Location{
    public:
        Location(const string& name);
        void addentity(Character*entity);
        void displayLocationInfo()const;
        string get_Location_name()const;
        vector<Character*> get_entities();
    private:
        string m_name;
        vector<Character*>entities;

};

#endif