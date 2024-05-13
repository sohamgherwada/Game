#ifndef MOVEBEHAVIOR_H
#define MOVEBEHAVIOR_H
#include "defs.h"
class Escape;
class MoveBehaviour {
    public:
        virtual void move(int,int,int&,int&) = 0; 
};
class EscapeeBehavior: public MoveBehaviour{
    public:
        void move(int,int,int&,int&); 
};
class VillianBehavior: public MoveBehaviour{
    public:
        void move(int,int,int&,int&); 
};
class RescuerBehavior: public MoveBehaviour{
    public:
        void move(int,int,int&,int&);
};
class RescuedBehavior: public MoveBehaviour{
    public:
        void move(int,int,int&,int&);
};
#endif