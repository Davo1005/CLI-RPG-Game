#include "../include/Utils.h"
#include "../include/Hero.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

 void printslow(const string &text) {
    int delay = 5;
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void print_monstertype(Monstertype monstertype) {
    if (monstertype == Monstertype::Goblin) {
        printslow("Giblin\n");
    }
    if (monstertype == Monstertype::Troll) {
        printslow("Troll\n");
    }
    if (monstertype == Monstertype::Dragon) {
        printslow("Dragon\n");
    }
}

void print_herotype(Herotype herotype) {
    if (herotype == Herotype::Warrior) {
        printslow("Warrior\n");
    }
    if (herotype == Herotype::Mage) {
        printslow("Mag\n");
    }
    if (herotype == Herotype::Rogue) {
        printslow("Rogue\n");
    }
}
