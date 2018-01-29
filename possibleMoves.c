//
// Created by aleksandra on 28.01.18.
//

#include "tetris.h"

bool I1(int blockY, int blockX, int *tmatrix);
bool I2(int blockY, int blockX, int *tmatrix);

bool J1(int blockY, int blockX, int *tmatrix);
bool J2(int blockY, int blockX, int *tmatrix);
bool J3(int blockY, int blockX, int *tmatrix);
bool J4(int blockY, int blockX, int *tmatrix);

bool L1(int blockY, int blockX, int *tmatrix);
bool L2(int blockY, int blockX, int *tmatrix);
bool L3(int blockY, int blockX, int *tmatrix);
bool L4(int blockY, int blockX, int *tmatrix);

bool T1(int blockY, int blockX, int *tmatrix);
bool T2(int blockY, int blockX, int *tmatrix);
bool T3(int blockY, int blockX, int *tmatrix);
bool T4(int blockY, int blockX, int *tmatrix);

bool O1(int blockY, int blockX, int *tmatrix);

bool S1(int blockY, int blockX, int *tmatrix);
bool S2(int blockY, int blockX, int *tmatrix);

bool Z1(int blockY, int blockX, int *tmatrix);
bool Z2(int blockY, int blockX, int *tmatrix);

bool CheckIfPossible(short int block, int blockY, int blockX, int position, int *tmatrix)
{
    switch(block)
    {
        case 0:
        {
            switch(position)
            {
                case 1:
                    return I1(blockY, blockX, tmatrix);
                case 2:
                    return I2(blockY, blockX, tmatrix);
                case 3:
                    return I1(blockY, blockX, tmatrix);
                case 4:
                    return I2(blockY, blockX, tmatrix);
            }
        }
        case 1:
        {
            switch(position)
            {
                case 1:
                    return J1(blockY, blockX, tmatrix);
                case 2:
                    return J2(blockY, blockX, tmatrix);
                case 3:
                    return J3(blockY, blockX, tmatrix);
                case 4:
                    return J4(blockY, blockX, tmatrix);
            }
        }
        case 2:
        {
            switch(position)
            {
                case 1:
                    return L1(blockY, blockX, tmatrix);
                case 2:
                    return L2(blockY, blockX, tmatrix);
                case 3:
                    return L3(blockY, blockX, tmatrix);
                case 4:
                    return L4(blockY, blockX, tmatrix);
            }
        }
        case 3:
        {
            switch(position)
            {
                case 1:
                    return T1(blockY, blockX, tmatrix);
                case 2:
                    return T2(blockY, blockX, tmatrix);
                case 3:
                    return T3(blockY, blockX, tmatrix);
                case 4:
                    return T4(blockY, blockX, tmatrix);
            }
        }
        case 4:
        {
            switch(position)
            {
                case 1:
                    return O1(blockY, blockX, tmatrix);
                case 2:
                    return O1(blockY, blockX, tmatrix);
                case 3:
                    return O1(blockY, blockX, tmatrix);
                case 4:
                    return O1(blockY, blockX, tmatrix);
            }
        }
        case 5:
        {
            switch(position)
            {
                case 1:
                    return S1(blockY, blockX, tmatrix);
                case 2:
                    return S2(blockY, blockX, tmatrix);
                case 3:
                    return S1(blockY, blockX, tmatrix);
                case 4:
                    return S2(blockY, blockX, tmatrix);
            }
        }
        case 6:
        {
            switch(position)
            {
                case 1:
                    return Z1(blockY, blockX, tmatrix);
                case 2:
                    return Z2(blockY, blockX, tmatrix);
                case 3:
                    return Z1(blockY, blockX, tmatrix);
                case 4:
                    return Z2(blockY, blockX, tmatrix);
            }
        }
    }
}
/*
 * X
 * X
 * X
 * X
 */
bool I1(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+2)*ELINROW)+blockX);
    int square4=*(tmatrix+((blockY+3)*ELINROW)+blockX);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * XXXX
 */
bool I2(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square3=*(tmatrix+(blockY*ELINROW)+blockX+2);
    int square4=*(tmatrix+(blockY*ELINROW)+blockX+3);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * XX
 * X
 * X
 */
bool J1(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square4=*(tmatrix+((blockY+2)*ELINROW)+blockX);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * XXX
 *   X
 */
bool J2(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square3=*(tmatrix+(blockY*ELINROW)+blockX+2);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX+2);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 *  X
 *  X
 * XX
 */
bool J3(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square3=*(tmatrix+((blockY+2)*ELINROW)+blockX);
    int square4=*(tmatrix+((blockY+2)*ELINROW)+blockX+1);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * X
 * XXX
 */
bool J4(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX+2);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * XX
 *  X
 *  X
 */
bool L1(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+2)*ELINROW)+blockX+1);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 *   X
 * XXX
 */
bool L2(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX+2);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX+2);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * X
 * X
 * XX
 */
bool L3(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+2)*ELINROW)+blockX);
    int square4=*(tmatrix+((blockY+2)*ELINROW)+blockX+1);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * XXX
 * X
 */
bool L4(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square3=*(tmatrix+(blockY*ELINROW)+blockX+2);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 *  X
 * XXX
 */
bool T1(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX+2);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * X
 * XX
 * X
 */
bool T2(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+2)*ELINROW)+blockX);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * XXX
 *  X
 */
bool T3(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square3=*(tmatrix+(blockY*ELINROW)+blockX+2);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 *  X
 * XX
 *  X
 */
bool T4(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+2)*ELINROW)+blockX+1);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * XX
 * XX
 */
bool O1(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 *  XX
 * XX
 */
bool S1(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+2);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * X
 * XX
 *  X
 */
bool S2(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+2)*ELINROW)+blockX+1);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 * XX
 *  XX
 */
bool Z1(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX);
    int square2=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+1)*ELINROW)+blockX+2);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

/*
 *  X
 * XX
 * X
 */
bool Z2(int blockY, int blockX, int *tmatrix)
{
    int square1=*(tmatrix+(blockY*ELINROW)+blockX+1);
    int square2=*(tmatrix+((blockY+1)*ELINROW)+blockX);
    int square3=*(tmatrix+((blockY+1)*ELINROW)+blockX+1);
    int square4=*(tmatrix+((blockY+2)*ELINROW)+blockX);
    if(square1==0 && square2==0 && square3==0 && square4==0)return true;
    return false;
}

