//
// Created by aleksandra on 29.01.18.
//

#include "tetris.h"

void IRotation(int *position, int *blockY, int *blockX, int *tmatrix, WINDOW *matrix)
{
    if(*position==1 || *position==3)
    {
        for(int r=0;r<4;++r)
        {
            for(int c=-3;c<=0;++c)
            {
                if(CheckIfPossible(0,*blockY+r,*blockX+c,2,tmatrix))
                {
                    DrawBlock(matrix,0,*blockY,*blockX,*position,' ', false);
                    *blockY+=r;
                    *blockX+=c;
                    *position=2;
                    DrawBlock(matrix,0,*blockY,*blockX,*position,ACS_CKBOARD, false);
                    return;
                }
            }
        }
    }
    else
    {
        for(int r=-3;r<=0;++r)
        {
            for(int c=0;c<=4;++c)
            {
                if(CheckIfPossible(0,*blockY+r,*blockX+c,1,tmatrix))
                {
                    DrawBlock(matrix,0,*blockY,*blockX,*position,' ', false);
                    *blockY+=r;
                    *blockX+=c;
                    *position=1;
                    DrawBlock(matrix,0,*blockY,*blockX,*position,ACS_CKBOARD, false);
                    return;
                }
            }
        }
    }
}

void JLTSZRotation(short int block, int *position, int *blockY, int *blockX, int *tmatrix, WINDOW *matrix)
{
    int lPosition=*position;
    for(int i=0;i<2;++i)
    {
        ++lPosition;
        if(lPosition==5)lPosition=1;

        for(int r=0;r<=3;++r)
        {
            for(int c=0;c<=3;++c)
            {
                if(CheckIfPossible(block,*blockY+r,*blockX+c,lPosition,tmatrix))
                {
                    DrawBlock(matrix,block,*blockY,*blockX,*position,' ', false);
                    *blockY+=r;
                    *blockX+=c;
                    *position=lPosition;
                    DrawBlock(matrix,block,*blockY,*blockX,*position,ACS_CKBOARD, false);
                    return;
                }
            }
        }

        for(int c=0;c<=3;++c)
        {
            if(CheckIfPossible(block,*blockY-1,*blockX+c,lPosition,tmatrix))
            {
                DrawBlock(matrix,block,*blockY,*blockX,*position,' ', false);
                *blockY+=-1;
                *blockX+=c;
                *position=lPosition;
                DrawBlock(matrix,block,*blockY,*blockX,*position,ACS_CKBOARD, false);
                return;
            }
        }
    }
}

void Rotation(short int block, int *blockY, int *blockX, int *position, int *tmatrix, WINDOW *matrix)
{
    if(block==0)IRotation(position, blockY, blockX, tmatrix, matrix);
    else JLTSZRotation(block, position, blockY, blockX, tmatrix, matrix);
}
