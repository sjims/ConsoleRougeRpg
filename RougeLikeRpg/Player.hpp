//
//  Player.hpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 06.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

//#include <stdio.h>
#include <string>
#endif /* Player_hpp */


class Player {
    
    
private:
    char swordOn='-',swordOff='.';
    char sword;
public:
    int HP = 100;
    int _playerX=0;
    int _playerY=0;
    char _dir='U';
    
    Player();
    void PrintInventory();
    void AddItem();
    void Move(char dir,class LevelLoader &level1);
    void Attack(LevelLoader &level1);
    void Clear(LevelLoader &level1);
};
