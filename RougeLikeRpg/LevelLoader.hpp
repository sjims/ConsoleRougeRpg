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
    
    void LoadFromFile();
    void LevelUpdate(char dir);
    void LevelRefresh();
    void PlayerCoords(int &x,  int &y );
    LevelLoader(class Player &_player);
    vector<string> level1;
    
private:    
    int _Plx= 0;
    int _Ply = 0;
    
};
