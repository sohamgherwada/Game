#include "MoveBehaviour.h"
#include "Escape.h"
void EscapeeBehavior::move(int oldRow, int oldCol,int& newRow, int& newCol){
    int rand = random(5);
    int r = 0;
    if (rand == 0)
    {
        r = oldRow+1;
    }else if(rand == 1){
        r = oldRow+2;
    }else if(rand==2){
        r = oldRow-1;
    }else if(rand==3){   
        r = oldRow-2;
    }else{
        r = oldRow;
    }
    int randCol = random(3);
    int c = 0;
    if (randCol==0)
    {
        c = oldCol+1;
    }else if(randCol==1){
        c = oldCol-1;
    }else{
        c= oldCol;
    }
    if (Escape::withinBounds(r,c))
    {
        newRow = r;
        newCol = c;
    }else{
        if (r >= MAX_ROW)
        {
            newRow = MAX_ROW-2;
        }
        if (c<0)
        {
            c = 1;
        }else{
            c= MAX_ROW-1;
        }
    }
    
    
}
void VillianBehavior::move(int oldRow, int oldCol,int& newRow, int& newCol){
    int rand = random(2);
    int r = 0;
    if (rand==0)
    {
        r = oldRow+1;
    
    }else{
        if (oldRow-1==MAX_ROW-8)
        {
            r = oldRow+1;
        }else{
            r = oldRow-1;
        } 
    }
    int c = 0;
    int randCol = random(3);
    if (randCol==0)
    {
        c = oldCol+1;
    }else if(randCol==1){
        
        c = oldCol-1;
    }else{
        c = oldCol;
    }
    if (Escape::withinBounds(r,c))
    {
        newRow = r;
        newCol = c;
    }else{
        if (r <= MAX_ROW-1)
        {
            newRow = MAX_ROW-2;
        }
        if (c<0||c>MAX_COL)
        {
            c = random(MAX_COL);
        }
    }

}
void RescuerBehavior::move(int oldRow, int oldCol,int& newRow, int& newCol){
    int r = oldRow+1;
    if (r<MAX_ROW)
    {
        newRow = r;
    }else{
        newRow = oldRow;
    }
    
    
}
void RescuedBehavior::move(int oldRow, int oldCol,int& newRow, int& newCol){
    newRow = oldRow-1;
}

