//
//  Player.cpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 06.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//
//test test
#include "Player.hpp"
#include <iostream>
#include "LevelLoader.hpp"
#include "Inventory.hpp"
Inventory inventory;
Player::Player()
{
    
    
    
}



void Player::Move(char dir)
{
    
    char _dir=dir;
    switch (_dir) {
        case 'R':
            _playerY+=1;
         
            break;
        case 'L':
            _playerY-=1;
         
            break;
        case 'U':
            _playerX-=1;
          
            break;
        case 'D':
            _playerX+=1;
                       break;
            
        default:
            break;
    }
    
    
}

void Player::PrintInventory()
{
    inventory.PrintInventory();
    
}


void Player::AddItem()
{
    inventory.num+=1;
}
