#include "../include/GameWorld.h"
#include "../include/Combatable.h"
#include "../include/Interactable.h"
#include "../include/Utils.h"


GameWorld::GameWorld() {
    currentLocation = nullptr;
}

void GameWorld::battle(Hero* hero, Monster* monster) {
    while (hero->get_helth() > 0 && monster->get_helth() > 0) 
    { 
        printslow("it is the hero's turn\n");
        printslow("1. Attack\n");
        printslow("2. Use Ability\n");
        printslow("3. Use Item\n");
        int n;
        cin >> n;
        switch (n) {
            case 1:
                hero->attack(monster);
                break;
            case 2:
                hero->useAbility(monster);
                break;
            case 3:
                printslow("You have such items at your disposal\n");
                hero->printItem();
                printslow("Which item do you want to use (0-2)?\n");
                int h;
                cin >> h;
                hero->useItem(h);
                break;
            default:
                printslow("Invalid choice\n");
                continue;
        }
        if (monster->get_helth() > 0) {
            printslow("Monster's turn\n");
            monster->attack(hero);
        }
        printslow("Hero health is " + std::to_string(hero->get_helth()) + " | Monster health is " + std::to_string(monster->get_helth()) + "\n");
    }
    if (hero->get_helth() > 0) {
        printslow("You defeated the monster\n");
        hero->gainXP(25);
    } else {
        printslow("Your hero is dead\n");
        printslow("Game over\n");
        exit(0);
    }
}

Location* GameWorld::getCurrentLocation() {
    return currentLocation;
}

void GameWorld::meetcharacter(Hero* hero, Location* location) {
    if (location->get_entities().size() == 0) {
        printslow("There is no personage here\n"); 
    }
    Character* encounter = location->get_entities()[0];
    if (dynamic_cast<NPC*>(encounter)) {
        NPC* npc = dynamic_cast<NPC*>(encounter);
        npc->getDialogue();
        printslow("After a long walk, you meet it\n");
        Monster* monster = new Monster("shreik", Monstertype::Goblin);
        printslow("The battle starts\n");
        battle(hero, monster);
    }
    if (dynamic_cast<Monster*>(encounter)) {
        Monster* monst = dynamic_cast<Monster*>(encounter);
        printslow("You meet a " + monst->get_name() + "\n");
        printslow("Prepare for battle\n");
        battle(hero, monst);
    }  
}

void GameWorld::addlocation(Location* location) {
    locations.push_back(location);
}

void GameWorld::setCurrentLocation(Location* location) {
    currentLocation = location;
    printslow("Current location set to: " + location->get_Location_name() + "\n");
}

void GameWorld::moveToLocation() {
    printslow("Which location do you want to move to?\n");
    for (int i = 0; i < locations.size(); i++) {
        printslow(std::to_string(i) + ". " + locations[i]->get_Location_name() + "\n");
    }
    int n;
    cin >> n;
    if (n >= 0 && n < locations.size()) {
        currentLocation = locations[n];
        printslow("Moved to location: " + currentLocation->get_Location_name() + "\n");
    } else {
        printslow("Invalid location index!\n");
    }
}

GameWorld::~GameWorld() {
    for (int i = 0; i < locations.size(); i++) {
        delete locations[i];
    }
    locations.clear();
    delete currentLocation;
}
