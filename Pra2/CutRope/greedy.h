//贪婪算法
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

int maxCutting(int len)
{
    if(len<2)
        return 0;
    if(len==2)
        return 1;
    if(len==3)
        return 2;
    
    int threeCount=len/3;

    //若最后剩下的长度为4时，采用2*2分割
    if(len-threeCount*3 == 1)
        --threeCount;

    int twoCount=(len-threeCount*3)/2;
    return (int)(pow(3,threeCount))*(int)(pow(2,twoCount));
}

