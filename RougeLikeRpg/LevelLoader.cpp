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
#include "Enemy.hpp"
Player *player;
vector <Enemy> enemes;

LevelLoader::LevelLoader(Player &pl)
{
    
    player=&pl;
    
    
    
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
                player->_playerX=i;
                player->_playerY=y;
            }
            if(level1[i][y]=='E')
            {
                enemes.push_back(Enemy(level1));
                enemes.back().X=i;
                enemes.back().Y=y;
            }
            
        }
         cout<<endl;
    }
    enemes[0].HP=0;
}




bool LevelLoader::CollisionCheck(int a, int b)
{
    
    if (level1[a][b] == '#')
    {
       return true;
    }
    if (level1[a][b] == 'E') {
        
        player->HP-=10;
        return true;
    }
    if (level1[a][b] == '-') {
        
        player->HP-=10;
        return true;
    }
    if (level1[a][b] == 'W') {
        
        player->AddItem();
        return false;
    }
    return false;
}

void LevelLoader::MoveEnemy()
{
    for(int i =0 ; i< enemes.size();i++)
    {
        enemes[i].Move(level1);
        
    }

}

void LevelLoader::LevelRefresh()
{
    
   
    
    level1[player->_playerX][player->_playerY]='X';
    for (int i= 0; i<level1.size(); i++) {
        for (int y = 0; y<level1[i].size(); y++) {
            
            cout<< level1[i][y];
            
        }
        cout<<endl;
    }
    
    cout<<player->HP<<"            "; player->PrintInventory();
    cout<<endl;
    
}
bool LevelLoader::IsAlive()
{
    if(player->HP<=0)
    {
        return false;
    }
    return true;
}

