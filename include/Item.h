#ifndef ITEM_H
#define ITEM_H
    #include"Character.h"
    #include<iostream>
    using namespace std;
    class Item{
        protected:
            string m_name;
            int m_value;
        public:
            Item()=default;
            Item(string name,int value):m_name(name),m_value(value){}
            virtual string getName()const=0;
            virtual void use_Item(Character*character)=0;
            virtual ~Item()=default;

    };

#endif