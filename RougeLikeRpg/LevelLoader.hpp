//
//  LevelLoader.hpp
//  RougeLikeRpg
//
//  Created by Ilia Sviatlovich on 04.05.17.
//  Copyright © 2017 Ilia Sviatlovich. All rights reserved.
//

#ifndef LevelLoader_hpp

#define LevelLoader_hpp


#endif /* LevelLoader_hpp */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>


using namespace std;
class LevelLoader {
    
public:
    void MoveEnemy();
    void LoadFromFile();
    void LevelUpdate(char dir);
    void LevelRefresh();
    void PlayerCoords(int &x,  int &y );
    LevelLoader(class Player &pl);
    vector<string> level1;
    bool CollisionCheck(int a, int b);
    
    bool IsAlive();
private:    
    int _Plx= 0;
    int _Ply = 0;
    
};
