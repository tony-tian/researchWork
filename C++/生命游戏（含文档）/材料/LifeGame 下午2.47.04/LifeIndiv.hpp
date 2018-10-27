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

class LifeIndiv
{
private:
    int x,y;
    bool status;
    int hp;
    int ATK;

public:
    LifeIndiv();
    LifeIndiv(int x,int y);
    void increaseHp(int x);
    void lifeTurns(bool statu_change);
    void eat(LifeIndiv &c);
};




#endif /* LifeIndiv_hpp */
