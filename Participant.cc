#include "Participant.h"

Participant::Participant(char a, int r,int c,MoveBehaviour*mb){
    avatar = a;
    row = r;
    col = c;
    behaviour = mb;
    dead=false;
}
Participant::~Participant(){
    delete behaviour;
}
void Participant::move(){
    if (!dead)
    {
        behaviour->move(row,col,row,col);
     
    }
}
char Participant::getAvatar(){
    return avatar;
}
int  Participant::getRow(){
    return row;
}
int Participant::getCol() {
    return col; 
}
void Participant::setMoveBehavior(MoveBehaviour *b) {
    delete behaviour;
    behaviour= b;
}
bool Participant::isDead(){
    return dead;
}
