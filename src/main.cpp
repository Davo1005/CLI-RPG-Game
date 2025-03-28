#include "../include/Character.h"
#include "../include/Combatable.h"
#include "../include/Interactable.h"
#include "../include/Item.h"
#include "../include/Magic_Amulet.h"
#include "../include/Sword.h"
#include "../include/HealthPotion.h"
#include "../include/Hero.h"
#include "../include/NPC.h"
#include "../include/Monster.h"
#include "../include/Location.h"
#include "../include/Quest.h"
#include "../include/QuestManager.h"
#include "../include/GameWorld.h"
#include "../include/Utils.h"
#include <iostream>
#include <vector>
using namespace std;

Hero* hero = nullptr;

int main() {
    cout << "Welcome to the game" << endl;
    cout << "Enter your hero name" << endl;
    string name;
    cin >> name;
    cout << "Choose your hero type" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Rogue" << endl;
    int n;
    cin >> n;
    Herotype herotype;
    switch (n) {
        case 1:
            herotype = Herotype::Warrior;
            break;
        case 2:
            herotype = Herotype::Mage;
            break;
        case 3:
            herotype = Herotype::Rogue;
            break;
        default:
            cout << "Invalid choice" << endl;
            return 0;
    }
    hero = new Hero(name, herotype);
    cout << "Your hero is created" << endl;
    cout << "You are in the village" << endl;
    Location* village = new Location("Village");
    Location* forest = new Location("Forest");
    Location* cave = new Location("Cave");
    Location* castle = new Location("Castle");
    village->addentity(hero);
    NPC* npc = new NPC("Villager", new QuestManager());
    village->addentity(npc);
    Monster* monster = new Monster("Goblin", Monstertype::Goblin);
    forest->addentity(monster);
    monster = new Monster("Troll", Monstertype::Troll);
    cave->addentity(monster);
    monster = new Monster("Dragon", Monstertype::Dragon);
    castle->addentity(monster);
    GameWorld* game = new GameWorld();
    game->addlocation(village);
    game->addlocation(forest);
    game->addlocation(cave);
    game->addlocation(castle);
    game->setCurrentLocation(village);
    while (true) {
        game->moveToLocation();
        game->meetcharacter(hero, game->getCurrentLocation());
    }
    return 0;
}