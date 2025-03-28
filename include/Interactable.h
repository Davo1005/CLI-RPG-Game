#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include "Character.h"

using namespace std;

class Interactable {
    public:
        virtual void interact(Character* target) = 0;
        virtual string getDialogue() const = 0;
};
#endif