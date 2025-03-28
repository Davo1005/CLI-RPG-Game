#include "../include/GameWorld.h"

void GameWorld::battle(Hero* hero, Monster* monster) {
    while (hero->get_helth() > 0 && monster->get_helth() > 0) { 
        cout << "it is the hero's turn" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Use Ability" << endl;
        cout << "3. Use Item" << endl;
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
                cout << "You have such items at your disposal" << endl;
                hero->printItem();
                cout << "Which item do you want to use (0-2)?" << endl;
                int h;
                cin >> h;
                hero->useItem(h);
                break;
            default:
                cout << "Invalid choice" << endl;
                continue;
        }
        if (monster->get_helth() > 0) {
            cout << "Monster's turn" << endl;
            monster->attack(hero);
        }
        cout << "Hero health is " << hero->get_helth() << " | Monster health is " << monster->get_helth() << endl;
    }
    if (hero->get_helth() > 0) {
        cout << "You defeated the monster" << endl;
        hero->gainXP(10);
    } else {
        cout << "Your hero is dead" << endl;
        cout << "Game over" << endl;
        exit(0);
    }
}

Location* GameWorld::getCurrentLocation() {
    return currentLocation;
}

void GameWorld::meetcharacter(Hero* hero, Location* location) {
    if (location->get_entities().size() == 0) {
        cout << "There is no personage here" << endl; 
    }
    Character* encounter = location->get_entities()[0];
    if (dynamic_cast<NPC*>(encounter)) {
        NPC* npc = dynamic_cast<NPC*>(encounter);
        npc->get_dialogue(hero);
        cout << "After a long walk, you meet it" << endl;
        Monster* monster = new Monster("shreik", Monstertype::Goblin);
        cout << "The battle starts" << endl;
        battle(hero, monster);
    }
    if (dynamic_cast<Monster*>(encounter)) {
        Monster* monst = dynamic_cast<Monster*>(encounter);
        cout << "You meet a " << monst->get_name() << endl;
        cout << "Prepare for battle" << endl;
        battle(hero, monst);
    }  
}

void GameWorld::addlocation(Location* location) {
    locations.push_back(location);
}

void GameWorld::setCurrentLocation(Location* location) {
    currentLocation = location;
    std::cout << "Current location set to: " << location->get_Location_name() << endl;
}

void GameWorld::moveToLocation() {
    cout << "Which location do you want to move to?" << endl;
    for (int i = 0; i < locations.size(); i++) {
        cout << locations[i]->get_Location_name() << endl;
    }
    int n;
    cin >> n;
    if (n >= 0 && n < locations.size()) {
        currentLocation = locations[n];
        std::cout << "Moved to location: " << currentLocation->get_Location_name() << endl;
    } else {
        std::cout << "Invalid location index!" << endl;
    }
}

GameWorld::~GameWorld() {
    for (int i = 0; i < locations.size(); i++) {
        delete locations[i];
    }
    locations.clear();
    delete currentLocation;
}
