#ifndef HERO_H
#define HERO_H
#include "Participant.h"
class Hero : public Participant{
    public:
        Hero(char c = 'H',int r = 0 , int co = 0,string n = "HARII");
        int causeDamage();
        bool isSafe();
        void incurDamage(Participant* p);
        int getHealth();
        string getName();
        bool rescuedHero();
    private:
        string name;
        int health;
        bool rescued;
};


#endif