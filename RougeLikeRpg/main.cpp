#include <iostream>
#include <string>
#include "myconio_mac.h" // conio заменитель для getch() - windows функция

#include "LevelLoader.hpp"
#include <time.h>

#include <chrono>
#include <thread>
#include <fcntl.h>
#include "Player.hpp"

using namespace std;
int mygetch();
int mykbhit();

int main()
{
    
 string refreshScreen (100,'\n');

    char input='p';
    
 bool dead = false;

    
   
   // level.level1[6][6] = 'X';
    
    
    Player player;
    LevelLoader level(player);
    level.LoadFromFile();
    while(true)
    {
        
        
        dead = player.HP>0;
   
        this_thread::sleep_for(chrono::milliseconds(150));
        if(mykbhit())
        {
            input = mygetch();
            if (input=='w')
        {
         
            level.LevelUpdate('U');
        }
           else if (input=='s')
            {
                
                level.LevelUpdate('D');
            }
          else  if (input=='d')
            {
               
                level.LevelUpdate('R');
            }
           else if (input=='a')
            {
               
                level.LevelUpdate('L');
            }
          
        }
  
    
   
    
    
        
        
        cout<<refreshScreen;
       level.LevelRefresh();
        
        
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
