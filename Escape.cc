#include "Escape.h"
Escape::Escape()
{
  srand((unsigned)time(NULL));
  int h1Col = (random(10)+7);
  h1 = new Hero('H',MAX_ROW-2,h1Col,"Harold");
  
  int h2Col = (random(10)+7);
  while(h1Col==h2Col){
    h2Col = (random(10)+7);
  }
  h2 = new Hero('T',MAX_ROW-2,h2Col,"Timmy");
  participants += h1;
  participants+=h2;
  numSnorcs = 0;
  printPit();
}

bool Escape::withinBounds(int r, int c){
    if (r<MAX_ROW-1)
    {
        if (c>0&&c<MAX_COL)
        {
            return true;
        }
    }
    return false;
}
void Escape::runEscape(){
  
  while (true)
  {
    
    sleep(1);
    int rand = random(10);
    
    if (rand<9 && numSnorcs<MAX_SNORCS)
    {
      
      spawnSnorc();
    }
    int randNinja = random(100);
    if (randNinja<NINJA_SPAWN)
    {
        spawnNinja();
    }
    
    
    printPit();
    moveParticipants();

    if (isOver())
    {
      break;
    }
    
    
  }
  printPit();
  printOutcome(h1);
  printOutcome(h2);
  
}
bool Escape::isOver(){
  
    if (h1->isDead()&&h2->isDead())
    {
      return true;
    }
    if (h1->isSafe()&&h2->isSafe())
    {
      return true;
    }
    if (h1->isDead()&&h2->isSafe())
    {
      return true;
    }
    if (h2->isDead()&&h1->isSafe())
    {
      return true;
    }
    return false;
}

void Escape::spawnSnorc(){
  int r = (MAX_ROW-2)-random(5);
  int c = random(MAX_COL-1)+1;
  int s = random(3)+2;
  Snorc* snorc = new Snorc(r,c,s);
  numSnorcs++;
  participants+=snorc;
}
void Escape::spawnNinja(){
    Ninja* ninja = new Ninja(0,random(MAX_COL-1)+1);
    participants+=ninja;
}
Participant* Escape::checkForCollision(Participant*p){
    Participant* arr[MAX_ARR];
    int size = 0;
    participants.convertToArray(arr,size);
    int i = 0;
    while (i<size)
    {
        if (arr[i]->getRow()==p->getRow()&&arr[i]->getCol()==p->getCol())
        {
            return arr[i];
        }
        i++;
        
    }
    return nullptr;
}
void Escape::moveParticipants(){
    Participant* arr[MAX_ARR];
    int size = 0;
    participants.convertToArray(arr,size);
    int i = 0;
    while (i<size)
    {

        if (!arr[i]->isSafe())
        {
            arr[i]->move();
        }
        Participant* collidedWith= checkForCollision(arr[i]);
        if(collidedWith!=nullptr){
            if (collidedWith!=arr[i])
            {
                
                collidedWith->incurDamage(arr[i]);
                arr[i]->incurDamage(collidedWith);
            }
        }
        i++;
    }
}

void Escape::printPit(){
    char templateGrid[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "                         ",
      "-------------------------"
  };
  Participant* arr[MAX_ARR];
  int size = 0;
  participants.convertToArray(arr,size);
  int i = 0;
  while (i<size)
  {
    templateGrid[arr[i]->getRow()][arr[i]->getCol()]=arr[i]->getAvatar();
    i++;
  }
  for (int i = 0; i < MAX_ROW+1; i++)
    {
        for (int j = 0; j < MAX_COL+1; j++)
        {
            cout <<templateGrid[i][j];
            if (i==MAX_ROW-2&&j==MAX_COL){
                if (h1->rescuedHero())
                {
                    cout<<"    "<<h1->getName()<<": "<< h1->getHealth()<<" was rescued!!!";

                }else if(h1->isDead()){
                    cout<<"    "<<h1->getName()<<": "<< h1->getHealth()<<" Deseased!!!";
                }else{
                    cout<<"    "<<h1->getName()<<": "<< h1->getHealth();
                }
                
                
            }else if(i==MAX_ROW-1&&j==MAX_COL){
                if (h2->rescuedHero())
                {
                    cout<<"    "<<h2->getName()<<": "<< h2->getHealth()<<" was rescued!!!";
                }else if(h2->isDead()){
                    cout<<"    "<<h2->getName()<<": "<< h2->getHealth()<<" Deseased!!!";
                }
                else{
                    cout<<"    "<<h2->getName()<<": "<< h2->getHealth();
                }
            }
        }
        cout << endl;
    }
}
void Escape::printOutcome(Hero* h){
    if (h->isSafe())
    {
        if (h->rescuedHero())
        {
            cout<<h->getName()<<" was rescued"<<endl;
        }else{
            cout<<h->getName()<<" has safely escaped"<<endl;
        }
    }
    if (h->isDead())
    {
        cout<<h->getName()<<" has died"<<endl;
    }
    
}