#ifndef SNORC_H
#define SNORC_H
#include "Participant.h"
class Snorc : public Participant{
    public:
        Snorc(int r = 0,int c = 0,int s = 0);
        int causeDamage();
        bool isSafe();
        void incurDamage(Participant* p);
    private:
        int strength;
};
#endif