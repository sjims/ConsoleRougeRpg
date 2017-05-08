//
//  LevelLoader.cpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 04.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//

#include <chrono>
#include <thread>
#include <fcntl.h>


#include "LevelLoader.hpp"
#include <fstream>
//#include <vector>
//#include <string>
using namespace std;
#include "Player.hpp"
#include "Enemy.hpp"

Player player;
//Enemy enemy;
vector <Enemy> enemes;

LevelLoader::LevelLoader()
{
    
    
    
    
    
}

void LevelLoader::LoadFromFile()
{
    ifstream inputFile;
   // ofstream outputFile;
    
   // outputFile.open("Level2.txt");
    
    //outputFile<<"Hello word";
    //outputFile.close();
    inputFile.open("/Users/sjims/Documents/Game_development/C_plus_plus_XCODE/RougeLikeRpg/RougeLikeRpg/Level1.txt");
    if(inputFile.fail())
    {
        cout<<"Loading Level Error"<<endl;
    }
    string level;
  
    
    while(getline(inputFile, level))
    {
        level1.push_back(level);
    }
    
level1[6][6] = 'E';
    for (int i= 0; i<level1.size(); i++) {
        for (int y = 0; y<level1[i].size(); y++) {
            
                        cout<< level1[i][y];
           if(level1[i][y]=='P')
           {
                player._playerX=i;
                player._playerY=y;
            }
            if(level1[i][y]=='E')
            {
                //enemy.X=i;
                //enemy.Y=y;
                enemes.push_back(Enemy());
                enemes.back().X=i;
                enemes.back().Y=y;
            }
            
        }
         cout<<endl;
    }
}

void LevelLoader::LevelUpdate(char dir)
{
    
    
   if((dir=='R')&&(!CollisionCheck(player._playerX, player._playerY+1)))
     
   {
   // player.Move(dir);
       player._playerY++;
    level1[player._playerX][player._playerY] = 'P';
    level1[player._playerX][player._playerY-1] = '.';
    
   }
    else if((dir=='L')&&(!CollisionCheck(player._playerX, player._playerY-1)))
        
    {
        player._playerY--;
        level1[player._playerX][player._playerY] = 'P';
        level1[player._playerX][player._playerY+1] = '.';
    }
    else if((dir=='U')&&(!CollisionCheck(player._playerX-1, player._playerY)))
        
    {
        player._playerX--;
        level1[player._playerX][player._playerY] = 'P';
        level1[player._playerX+1][player._playerY] = '.';
    }
    else if((dir=='D')&&(!CollisionCheck(player._playerX+1, player._playerY)))
        
    {
         player._playerX++;
        level1[player._playerX][player._playerY] = 'P';
        level1[player._playerX-1][player._playerY] = '.';
    }

    

    
  }


bool LevelLoader::CollisionCheck(int a, int b)
{
    
    if (level1[a][b] == '#')
    {
       return true;
    }
    if (level1[a][b] == 'E') {
        
        player.HP-=10;
        return true;
    }
    if (level1[a][b] == 'W') {
        
        player.AddItem();
        return false;
    }
    return false;
}

void LevelLoader::MoveEnemy()
{
   
   // cout<<enemyDir<<endl;
    for(int i =0 ; i< enemes.size();i++)
    {
       char enemyDir = enemes[i].GotDir();
        if((level1[enemes[i].X][enemes[i].Y+1] != '#')&&(enemyDir=='R'))
        {
            enemes[i].Y++;
            level1[enemes[i].X][enemes[i].Y] = 'E';
            level1[enemes[i].X][enemes[i].Y-1] = '.';
            
            
        }
        if((level1[enemes[i].X][enemes[i].Y-1] != '#')&&(enemyDir=='L'))
            
        {
            enemes[i].Y--;
            level1[enemes[i].X][enemes[i].Y] = 'E';
            level1[enemes[i].X][enemes[i].Y+1] = '.';
            
        }
         if((level1[enemes[i].X-1][enemes[i].Y] != '#')&&(enemyDir=='U'))
            
        {
            enemes[i].X--;
            level1[enemes[i].X][enemes[i].Y] = 'E';
            level1[enemes[i].X+1][enemes[i].Y] = '.';
            
        }
         if((level1[enemes[i].X+1][enemes[i].Y] != '#')&&(enemyDir=='D'))
            
        {
            enemes[i].X++;
            level1[enemes[i].X][enemes[i].Y] = 'E';
            level1[enemes[i].X-1][enemes[i].Y] = '.';
             
        }
        
        
    }
    
    
}

void LevelLoader::LevelRefresh()
{
 
    
    for (int i= 0; i<level1.size(); i++) {
        for (int y = 0; y<level1[i].size(); y++) {
            
            cout<< level1[i][y];
            
        }
        cout<<endl;
    }
    
    cout<<player.HP<<"            "; player.PrintInventory();
    cout<<endl;
    
    MoveEnemy();
}
bool LevelLoader::IsAlive()
{
    if(player.HP<=0)
    {
        return false;
    }
    return true;
}

void LevelLoader::PlayerCoords(int &x,  int &y )
{
    _Plx= x;
    _Ply = y;
    
}

