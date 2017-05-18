#include <iostream>
#include <string>
#include "myconio_mac.h" // conio заменитель для getch() - windows функция
#include "LevelLoader.hpp"
//#include <time.h>

//#include <chrono>
#include <thread>
#include <fcntl.h>
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;
int mygetch();
int mykbhit();

int main()
{
    Player pl;

    string refreshScreen (100,'\n');
    char input='p';
    
    
    LevelLoader level(pl);
    
    
    level.LoadFromFile();
    
    int canClear =0;
    
    while(level.IsAlive())
    {
        this_thread::sleep_for(chrono::milliseconds(10));
        if(canClear==20)
        {
           level.MoveEnemy();
           pl.Clear(level);
           canClear=0;
            
        }
        if(mykbhit())
        {
            input = mygetch();
            if (input=='w')
        {
            pl.Move('U', level);
            //level.LevelUpdate('U');
        }
           else if (input=='s')
            {
             pl.Move('D', level);
               // level.LevelUpdate('D');
            }
          else  if (input=='d')
            {
               pl.Move('R', level);
                //level.LevelUpdate('R');
            }
           else if (input=='a')
            {
               pl.Move('L', level);
                //level.LevelUpdate('L');
            }
           else if (input=='f')
           {
               
               pl.Attack(level);
           }
          
        }
  
    
   
    
    
        
        
        cout<<refreshScreen;
       level.LevelRefresh();
        canClear++;
        
    }
    return 0;
}









int mygetch()
{
    struct termios oldt,
    newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
int mykbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    
    return 0;
}
