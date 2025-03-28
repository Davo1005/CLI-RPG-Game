#ifndef QUEST
#define QUEST
#include"Hero.h"
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
                cout<<"You do your quest succesfully. Your gained xp are"<<m_xp<<endl;
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