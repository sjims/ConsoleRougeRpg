//
//  Player.cpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 06.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//

#include "Player.hpp"
#include <iostream>
#include "LevelLoader.hpp"

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

