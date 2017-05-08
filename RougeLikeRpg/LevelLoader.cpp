//
//  LevelLoader.cpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 04.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//

#include "LevelLoader.hpp"
#include <fstream>
//#include <vector>
//#include <string>
using namespace std;
#include "Player.hpp"

 Player player;


LevelLoader::LevelLoader(class Player &_player)
{
    player = _player;
    
    
    
}

void LevelLoader::LoadFromFile()
{
    ifstream inputFile;
    ofstream outputFile;
    
    outputFile.open("Level2.txt");
    
    //outputFile<<"Hello word";
    outputFile.close();
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
    

    for (int i= 0; i<level1.size(); i++) {
        for (int y = 0; y<level1[i].size(); y++) {
            
                        cout<< level1[i][y];
           if(level1[i][y]=='P')
           {
                player._playerX=i;
                player._playerY=y;
                           }
        }
         cout<<endl;
    }
}

void LevelLoader::LevelUpdate(char dir)
{
    
   if((level1[player._playerX][player._playerY+1] != '#')&&(dir=='R'))
     
   {
    player.Move(dir);
    level1[player._playerX][player._playerY] = 'P';
    level1[player._playerX][player._playerY-1] = '.';
    
   }
    else if((level1[player._playerX][player._playerY-1] != '#')&&(dir=='L'))
        
    {
        player.Move(dir);
        level1[player._playerX][player._playerY] = 'P';
        level1[player._playerX][player._playerY+1] = '.';
    }
    else if((level1[player._playerX-1][player._playerY] != '#')&&(dir=='U'))
        
    {
        player.Move(dir);
        level1[player._playerX][player._playerY] = 'P';
        level1[player._playerX+1][player._playerY] = '.';
    }
    else if((level1[player._playerX+1][player._playerY] != '#')&&(dir=='D'))
        
    {
        player.Move(dir);
        level1[player._playerX][player._playerY] = 'P';
        level1[player._playerX-1][player._playerY] = '.';
    }
   else{
       player.HP-=10;
       
   }
    //нажатая кнопка
    //подвигать игрока
    //playerX,PlayerY
    //подвигать врага
   /* for(int i =0 ; i< enimes.size();i++)
    {
        if
        enemy[i].Update();
    }*/
   // LevelRefresh();
}
void LevelLoader::LevelRefresh()
{
 
    //int xX = player._playerX;
    //int yY = player._playerY;
    
    
    
    //level1[xX][yY] = 'P';
    for (int i= 0; i<level1.size(); i++) {
        for (int y = 0; y<level1[i].size(); y++) {
            
            cout<< level1[i][y];
            
        }
        cout<<endl;
    }
    
    cout<<player.HP<<endl;;
}

void LevelLoader::PlayerCoords(int &x,  int &y )
{
    _Plx= x;
    _Ply = y;
    
}

