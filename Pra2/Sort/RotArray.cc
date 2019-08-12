#include <iostream>
using std::endl;
using std::cout;

int Min(int *numbers,int len)
{
    if(numbers==nullptr || len<=0)
    {
        cout<<"Invalid parameters!"<<endl;
        exit(0);
    }

    int lIndex=0;
    int rIndex=len-1;
    int mIndex=0;
    while(numbers[lIndex]>=numbers[rIndex])
    {
        if(rIndex-lIndex == 1)
        {
            mIndex=rIndex;
            break;
        }

        mIndex=(rIndex+lIndex)/2;
        if(numbers[lIndex]<=numbers[mIndex])
        {
            lIndex=mIndex;
        }
        else if(numbers[rIndex]>=numbers[mIndex])
        {
            rIndex=mIndex;
        }
    }

    return numbers[mIndex];
}


int main()
{
    int num[]={3,4,5,1,2};
    cout<<Min(num,5)<<endl;;
    return 0;
}

