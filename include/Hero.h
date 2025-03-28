#ifndef HERO_H
#define HERO_H
    #include"Character.h"
    #include"Combatable.h"
    #include"Interactable.h"
    #include"Item.h"
    #include<vector>
    #include"Magic_Amulet.h"
    #include"Sword.h"
    #include"HealthPotion.h"
    enum class Herotype{
        Warrior,
        Mage,
        Rogue
    };
    
       
    class Hero: public Character, public Combatable, public Interactable{
        private:
            vector<Item*>m_inventory;
            int m_level;
            int m_XP;
            const int xptolevelup=100;
            Herotype m_herotype;
        public:
            Hero(string name,Herotype herotype);
            void addItem(Item* inventory);
            void displayStats()const override;
            void takeDamage(int damage)override;
            void attack(Character* target)override;
            void useAbility(Character* target)override;
            void interact(Character* target)override;
            void useItem(int index);
            void printItem()const;
            void gainXP(int xp);
            void levelup();
            int getlevel();
            string getDialogue()const override;
            ~Hero();

    };
#endif