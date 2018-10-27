//
//  LifeIndiv.cpp
//  LifeGame
//
//  Created by Renaissan Ti on 16/7/9.
//  Copyright © 2016年 田亦庄. All rights reserved.
//

#include "LifeIndiv.hpp"
#include <iostream>
#include <stdlib.h>

LifeIndiv::LifeIndiv()
{
    ATK=0;
    hp=1;
    x=rand();
    y=rand();
    status=true;
}

LifeIndiv::LifeIndiv(int x,int y)
{
    ATK=0;
    hp=1;
    this->x=x;
    this->y=y;
    status=true;
}

void LifeIndiv::increaseHp(int x)
{
    this->x+=x;
}

void LifeIndiv::eat(LifeIndiv &c)
{
    this->hp+=c.hp;
    c.status=false;
}

void LifeIndiv::lifeTurns(bool status_change)
{
    status=status_change;
}


