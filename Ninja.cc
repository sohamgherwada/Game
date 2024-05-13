#include "Ninja.h"
Ninja::Ninja(int r,int c):Participant('N', r, c, new RescuerBehavior()){
    strength = -1;
    poisoned = false;
}
void Ninja::incurDamage(Participant* p){
    
    if (p->causeDamage()>0)
    {
        poisoned = true;
        avatar = 'S';
        strength = random(3)+6;
        setMoveBehavior(new VillianBehavior());
    }else if(p->causeDamage()==0)
    {
        if(!poisoned){
            setMoveBehavior(new RescuedBehavior());
            row = row -1;
        }
    }
    
}
int Ninja::causeDamage(){
    return strength;
}
bool Ninja::isSafe(){
    if (getRow()<0)
    {
        avatar = '-';
        return true;
    }else if(getRow()>=MAX_ROW-1){
        avatar = '-';
        return true;
    }
    return false;
}