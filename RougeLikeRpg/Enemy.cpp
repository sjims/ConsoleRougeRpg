//
//  Enemy.cpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 08.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//

#include "Enemy.hpp"

#include <random>
#include <time.h>
#include <iostream>
#include "LevelLoader.hpp"
using namespace std;
vector<string> lv;
Enemy::Enemy(vector<string> &level)
{
    lv=level;
    
    
}


char Enemy::GotDir(){
    
   static std::mt19937 randomGenerator(int(time(NULL)));
    
    std::uniform_int_distribution<int> choice(0,3);
   
    switch(choice(randomGenerator))
    {
        case 0: _dir='R'; return 'R';
            break;
        case 1: _dir='L'; return 'L';
            break;
        case 2: _dir='U'; return 'U';
            break;
        case 3: _dir='D'; return 'D';
            break;
        
    }
    return 'S';
    
}

void Enemy::Move(vector<string> &level){
   //_dir = GotDir();
    if((GotDir()=='R')&&(!CollisionCheck(X,Y+1,level)))
    {
        Y++;
        level[X][Y]='E';
        level[X][Y-1] = '.';
       
    }
    if((GotDir()=='L')&&(!CollisionCheck(X,Y-1,level)))
    {
        Y--;
        level[X][Y]='E';
        level[X][Y+1] = '.';
        
    }
    if((GotDir()=='U')&&(!CollisionCheck(X-1,Y,level)))
    {
        X--;
        level[X][Y]='E';
        level[X+1][Y] = '.';
       
    } if((GotDir()=='D')&&(!CollisionCheck(X+1,Y,level)))
    {
        X++;
        level[X][Y]='E';
        level[X-1][Y] = '.';
        
    }
    
}

bool Enemy::CollisionCheck(int a, int b, vector<string> level)
{
    //lv->lv[a][b];
    if (level[a][b] == '#')
    {
        return true;
    }
    if (level[a][b] == 'E') {
        
      //  lv->HP-=10;
        return true;
    }
    if (level[a][b] == '-') {
        
        //player->HP-=10;
        return true;
    }
    if (level[a][b] == 'W') {
        
       // player->AddItem();
        return true;
    }
    return false;
}
