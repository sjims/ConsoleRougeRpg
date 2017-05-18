//
//  Enemy.hpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 08.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

//#include <stdio.h>

#include <vector>
#include <string>
using namespace std;
class Enemy {
    
    
private:
    
    
public:
    int X=0;
    int Y=0;
    int HP=10;
    char _dir = 'R';
    char GotDir();

    Enemy(vector<string> &level);
    bool CollisionCheck(int a, int b,vector<string> level);
    void Move(vector<string> &level);
};




#endif /* Enemy_hpp */


