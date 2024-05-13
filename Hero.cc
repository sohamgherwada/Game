#include "Hero.h"
Hero::Hero(char a,int r,int c,string na):Participant(a,r,c,new EscapeeBehavior()){
    name = na;
    health = MAX_HEALTH;
    rescued = false;
}
void Hero::incurDamage(Participant* p){
    int dam = p->causeDamage();
    
    if (dam == RESCUE)
    {
        if(!rescued){
            rescued = true;

            setMoveBehavior(new RescuedBehavior());
    
        }
        
        return;
    }else{
        rescued = false;
        setMoveBehavior(new EscapeeBehavior());
    }
    health-=dam;
    if (health <= 0){
        avatar = '+';
        health = 0;
        dead = true;
    }
}
int Hero::causeDamage(){
    return 0;
}
bool Hero::isSafe(){
    if (getRow()<=0)
    {
        avatar = '-';
        return true;
    }
    return false;
}
int Hero::getHealth(){
    return health;
}
string Hero::getName(){
    return name;
}
bool Hero::rescuedHero(){

    return rescued;
}