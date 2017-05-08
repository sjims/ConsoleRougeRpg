//
//  Player.hpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 06.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#endif /* Player_hpp */


class Player {
    
    
private:
   
    
public:
    int HP = 100;
    int _playerX=0;
    int _playerY=0;
    
    Player();
  
    void Move(char dir);
    void PrintInventory();
    void AddItem();
};
