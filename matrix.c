//
// Created by aleksandra on 28.01.18.
//

#include "tetris.h"

void Changetmatrix(short int block, int blockY, int blockX, int position, int *tmatrix, int value)
{
    switch (block)
    {
        case 0:
        {
            switch(position)
            {
                case 1:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+3)*ELINROW)+blockX)=value;
                    break;
                }
                case 2:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+2)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+3)=value;
                    break;
                }
                case 3:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+3)*ELINROW)+blockX)=value;
                    break;
                }
                case 4:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+2)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+3)=value;
                    break;
                }
            }
            break;
        }
        case 1:
        {
            switch(position)
            {
                case 1:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX)=value;
                    break;
                }
                case 2:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+2)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+2)=value;
                    break;
                }
                case 3:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX+1)=value;
                    break;
                }
                case 4:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+2)=value;
                    break;
                }
            }
            break;
        }
        case 2:
        {
            switch(position)
            {
                case 1:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX+1)=value;
                    break;
                }
                case 2:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX+2)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+2)=value;
                    break;
                }
                case 3:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX+1)=value;
                    break;
                }
                case 4:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+2)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            switch(position)
            {
                case 1:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+2)=value;
                    break;
                }
                case 2:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX)=value;
                    break;
                }
                case 3:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+2)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    break;
                }
                case 4:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX+1)=value;
                    break;
                }
            }
            break;
        }
        case 4:
        {
            *(tmatrix+(blockY*ELINROW)+blockX)=value;
            *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
            *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
            *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
        }
        case 5:
        {
            switch(position)
            {
                case 1:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+2)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    break;
                }
                case 2:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX+1)=value;
                    break;
                }
                case 3:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+2)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    break;
                }
                case 4:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX+1)=value;
                    break;
                }
            }
            break;
        }
        case 6:
        {
            switch(position)
            {
                case 1:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+2)=value;
                    break;
                }
                case 2:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX)=value;
                    break;
                }
                case 3:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX)=value;
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+2)=value;
                    break;
                }
                case 4:
                {
                    *(tmatrix+(blockY*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX)=value;
                    *(tmatrix+((blockY+1)*ELINROW)+blockX+1)=value;
                    *(tmatrix+((blockY+2)*ELINROW)+blockX)=value;
                    break;
                }
            }
            break;
        }
    }
}