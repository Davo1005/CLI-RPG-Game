#ifndef HERO_H
#define HERO_H
enum class Herotype{
    Warrior,
    Mage,
    Rogue
};
    #include"Character.h"
    #include"Combatable.h"
    #include"Interactable.h"
    #include"Item.h"
    #include<vector>
    #include"Magic_Amulet.h"
    #include"Utils.h"
    #include"Sword.h"
    #include"HealthPotion.h"
       
    class Hero: public Character, public Combatable, public Interactable{
        private:
            vector<Item*>m_inventory;
            int m_level;
            int m_XP;
            const int xptolevelup=50;
            Herotype m_herotype;
        public:
            Hero(string name,Herotype herotype);
            void addItem(Item* inventory);
            void displayStats()const override;
            void takeDamage(int damage)override;
            void attack(Character* target);
            void useAbility(Character* target);
            void interact(Character* target);
            void recover(int value);
            void improve_defense(int value);
            string getName()const;
            void useItem(int index);
            void printItem()const;
            void gainXP(int xp);
            
            void levelup();
            int getlevel();
            string getDialogue()const override;
            virtual ~Hero();

    };
#endif