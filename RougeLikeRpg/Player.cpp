//
//  Player.cpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 06.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//
//test test
#include "Player.hpp"
#include "LevelLoader.hpp"
#include "Inventory.hpp"
Inventory inventory;
Player::Player()
{
    
    
    
}


void Player::PrintInventory()
{
    inventory.PrintInventory();
    
}


void Player::AddItem()
{
    inventory.num+=1;
}

void Player::Move(char dir, LevelLoader &level1)
{
    _dir = dir;
    if((dir=='R')&&(!level1.CollisionCheck(_playerX, _playerY+1)))
        
    {
        
        _playerY++;
        //level1[_playerX][_playerY] = 'P';
        level1.level1[_playerX][_playerY-1] = '.';
        
    }
    else if((dir=='L')&&(!level1.CollisionCheck(_playerX,_playerY-1)))
        
    {
        _playerY--;
        //level1[player->_playerX][player->_playerY] = 'P';
        level1.level1[_playerX][_playerY+1] = '.';
    }
    else if((dir=='U')&&(!level1.CollisionCheck(_playerX-1,_playerY)))
        
    {
        _playerX--;
        //level1[player->_playerX][player->_playerY] = 'P';
        level1.level1[_playerX+1][_playerY] = '.';
    }
    else if((dir=='D')&&(!level1.CollisionCheck(_playerX+1, _playerY)))
        
    {
        _playerX++;
        //level1[player->_playerX][player->_playerY] = 'P';
        level1.level1[_playerX-1][_playerY] = '.';
    }
   /* else if((dir=='f')&&(!CollisionCheck(player->_playerX+1, player->_playerY)))
        
    {
        if(dir=='U'){
            level1[player->_playerX-1][player->_playerY] = '-';
            
        }
        else if(dir=='D'){
            level1[player->_playerX][player->_playerY] = '-';
            
        }
        else if(dir=='L'){
            level1[player->_playerX][player->_playerY] = '-';
            
        }
        else if(dir=='R'){
            level1[player->_playerX][player->_playerY] = '-';
            
        }
    }
    
    */
    
    
}
void Player::Attack(LevelLoader &level1)
{
    sword = swordOn;
    if((_dir=='U')&&(!level1.CollisionCheck(_playerX-1,_playerY)))
        
    {
        level1.level1[_playerX-1][_playerY] = sword;
        
    }
    else if(_dir=='D'){
         level1.level1[_playerX+1][_playerY] = sword;
        
    }
    else if(_dir=='L'){
         level1.level1[_playerX][_playerY] = sword;
        
    }
    else if(_dir=='R'){
         level1.level1[_playerX][_playerY] = sword;
        
    }

    // level1.level1[_playerX-1][_playerY] = 'z';
}
void Player::Clear(LevelLoader &level1)
{
    sword = swordOff;
    if((_dir=='U')&&(!level1.CollisionCheck(_playerX-1,_playerY)))
        
    {
    level1.level1[_playerX-1][_playerY] = swordOff;
    }
}
