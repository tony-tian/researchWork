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
    memset(LifeArray,0,22*22*sizeof(int));
    //memset(status,0,102*102*sizeof(int));
    life_num=0;
    dead_num=0;
    life_sum=0;
    dead_sum=0;
    step=0;
    memset(increase,0,5000*sizeof(int));
}

void LifeIndiv::clearWorld()
{
    memset(LifeArray,0,22*22*sizeof(int));
    //memset(status,0,102*102*sizeof(int));
    life_num=0;
    dead_num=0;
    life_sum=0;
    dead_sum=0;
    step=0;
    memset(increase,0,5000*sizeof(int));
}

void LifeIndiv::createWorldRandom()
{
    memset(LifeArray,0,22*22*sizeof(int));
    for (int i=1; i<=20; i++)
        for (int j=1; j<=20; j++)
        {
            if (rand()%3==0)
            {
                LifeArray[i][j]=rand()%2;
            }
            else
            {
                LifeArray[i][j]=0;
            }
            if(LifeArray[i][j]==1)
            {
                life_num++;
                life_sum++;
            }
        }
}

void LifeIndiv::evolve()
{
    int tmp[22][22];
    int m_life=life_num;
    dead_num=0;
    for(int x = 1; x <=20; x++)
    {
        for(int y = 1; y <= 20; y++)
        {
            int sum1 = LifeArray[x+1][y] + LifeArray[x+1][y-1] + LifeArray[x][y-1] + LifeArray[x-1][y-1]
            + LifeArray[x-1][y] + LifeArray[x-1][y+1] + LifeArray[x][y+1] + LifeArray[x+1][y+1];
            switch (sum1)
            {
                case 3:
                    tmp[x][y]=1;
                    if(LifeArray[x][y]==0)
                    {
                        life_num++;
                        life_sum++;
                    }
                    break;

                case 2:
                    tmp[x][y]=LifeArray[x][y];
                    break;

                default:
                    tmp[x][y]=0;
                    if(LifeArray[x][y]==1)
                    {
                        dead_num++;
                        life_num--;
                    }
                    break;
            }
        }
    }
    dead_sum+=dead_num;
    step++;
    increase[step]=life_num-m_life;
    memcpy(LifeArray, tmp, 22 * 22 * sizeof(int));
}

int LifeIndiv::getStatus(int i,int j)
{
    int a=LifeArray[i][j];
    return a;
}

int LifeIndiv::getStatistics(int i)
{
    switch (i)
    {
        case 1:
            return life_num;
            break;

        case 2:
            return dead_num;
            break;

        case 3:
            return life_sum;
            break;

        case 4:
            return dead_sum;
            break;

        default:
            break;
    }
}

void LifeIndiv::createWorldCrowd()
{
    memset(LifeArray,0,22*22*sizeof(int));
    for (int i=1; i<=20; i++)
        for (int j=1; j<=20; j++)
        {
            LifeArray[i][j]=rand()%2;
            if(LifeArray[i][j]==1)
            {
                life_num++;
                life_sum++;
            }
        }
}

int LifeIndiv::getStep()
{
    return step;
}

void LifeIndiv::create10Cell()
{
    clearWorld();

    for(int i=6;i<=15;i++)
        LifeArray[10][i]=1;
    life_num=10;
    life_sum=life_num;
}

void LifeIndiv::create3Boats()
{
    clearWorld();

    //first
    for(int i=2;i<6;i++)
    {
        LifeArray[4][i]=1;
    }
    LifeArray[3][1]=1;
    LifeArray[3][5]=1;
    LifeArray[2][5]=1;
    LifeArray[1][4]=1;

    //second
    LifeArray[8][1]=1;
    LifeArray[9][2]=1;
    LifeArray[9][3]=1;
    LifeArray[10][3]=1;
    LifeArray[11][3]=1;
    LifeArray[12][2]=1;

    //third
    LifeArray[15][4]=1;
    LifeArray[16][5]=1;
    LifeArray[17][5]=1;
    LifeArray[17][1]=1;
    LifeArray[18][5]=1;
    LifeArray[18][4]=1;
    LifeArray[18][3]=1;
    LifeArray[18][2]=1;
}
