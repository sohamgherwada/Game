#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include "defs.h"
#include "MoveBehaviour.h"
class MoveBehaviour;
class Participant {
    protected:
        char avatar;
        bool dead;
        int row;
        int col;
        MoveBehaviour* behaviour;
    public:
        Participant(char a ='G', int r = 0,int c = 0, MoveBehaviour* b=NULL);
        virtual ~Participant();
        virtual void incurDamage(Participant*p)=0;
        virtual int causeDamage() = 0;
        virtual bool isSafe() = 0;
        void move();
        char getAvatar();
        int getRow();
        int getCol();
        void setMoveBehavior(MoveBehaviour *b);
        bool isDead();
};
#endif