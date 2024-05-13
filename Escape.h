#ifndef ESCAPE_H
#define ESCAPE_H
#include "Participant.h"
#include "Hero.h"
#include "List.h"
#include "Snorc.h"
#include "Ninja.h"
class Escape
{
private:
    int numSnorcs;
    void spawnSnorc();
    void spawnNinja();
    void moveParticipants();
    Hero*h1;
    Hero*h2;
    List <Participant*> participants;
    Participant* checkForCollision(Participant*p);
    bool isOver();
    void printPit();
    void printOutcome(Hero* h);
    
public:
    Escape();
    void runEscape();
    static bool withinBounds(int r,int c);
};

#endif