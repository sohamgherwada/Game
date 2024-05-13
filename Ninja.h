#ifndef NINJA_H
#define NINJA_H
#include "Participant.h"
class Ninja : public Participant{
    public:
        Ninja(int r = 0,int c = 0);
        int causeDamage();
        bool isSafe();
        void incurDamage(Participant* p);
    private:
        int strength;
        bool poisoned;
};
#endif