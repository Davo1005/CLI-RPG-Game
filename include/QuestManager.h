#ifndef QUESTMANAGER
#define QUESTMANAGER
    #include"Quest.h"
    class QuestManager {
    public:
        QuestManager(); 
        void add_quest(Quest* quest);
        void complete_quest(Hero* hero, Quest* quest);
        bool checkQuestCompletion(Quest* quest);
        void displayActiveQuests() const;
        void displayCompletedQuests() const;
        void assign_quest(Hero* hero, Quest* quest);
        Quest* get_Quest();
        ~QuestManager();
    private:
        vector<Quest*> activeQuests;
        vector<Quest*> completedQuests; 
    };
#endif
