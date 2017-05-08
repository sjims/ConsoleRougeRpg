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

Enemy::Enemy()
{
    
    
    
}


char Enemy::GotDir(){
    
   static std::mt19937 randomGenerator(int(time(NULL)));
    
    std::uniform_int_distribution<int> choice(0,3);
   
    switch(choice(randomGenerator))
    {
        case 0: return 'R';
            break;
        case 1: return 'L';
            break;
        case 2: return 'U';
            break;
        case 3: return 'D';
            break;
        
    }
    return 'S';
    
}
