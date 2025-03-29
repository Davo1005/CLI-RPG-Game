#ifndef GAMEWORLD
#define GAMEWORLD
    #include"Character.h"
    #include"Location.h"
    #include"Hero.h"
    #include"Monster.h"
    #include"NPC.h"
    #include"Utils.h"
    #include<memory>
    class GameWorld{
    public:
        GameWorld();
        void addlocation(Location*location);
        Location* getCurrentLocation();
        void setCurrentLocation(Location* location);
        void moveToLocation();
        void meetcharacter(Hero* hero,Location* location ); 
        void battle(Hero* hero,Monster* monster);
        ~GameWorld();
    private:
        Location* currentLocation;
        vector<Location*>locations;

    };
#endif