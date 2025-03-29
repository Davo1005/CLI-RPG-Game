#ifndef QUEST
#define QUEST
#include"Hero.h"
#include "Utils.h"
    class Quest{
        public:
            Quest(string description,int xp)
            {
                m_description=description;
                completed=false;
                m_xp=xp;
            }
            
            string get_description()
            {
                return m_description;
            }
            
            void completedQuest(Hero*hero)
            {
                completed=true;
                printslow("You do your quest successfully. Your gained XP are " + std::to_string(m_xp) + "\n");
                hero->gainXP(m_xp);     
            }
            
            bool iscompleted()
            {
                return completed;
            }
        private:
            string m_description;
            bool completed;
            int m_xp;

    };
#endif