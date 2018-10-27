//
//  LifeIndiv.hpp
//  LifeGame
//
//  Created by Renaissan Ti on 16/7/9.
//  Copyright © 2016年 田亦庄. All rights reserved.
//

#ifndef LifeIndiv_hpp
#define LifeIndiv_hpp

#include <stdio.h>
#include <wx/grid.h>

class LifeIndiv
{
private:
    int LifeArray[22][22];
    //int status[102][102];
    int life_num,dead_num,life_sum,dead_sum;
    //life_num equals real-time living block
    //dead_num equals dead blocks in last evolve-process
    //life_sum equals the addition of living blocks in all turns
    //dead_sum equals the addtion of dead_num in all turns
    int step,increase[5000];

public:
    LifeIndiv();
    void createWorldRandom();
    //int* GetWorldInfo();
    void evolve();
    int getStatus(int i, int j);
    int getStatistics(int i);
    void clearWorld();
    void createWorldCrowd();
    int getStep();
    void create10Cell();
    void create3Boats();
};

#endif /* LifeIndiv_hpp */
