//考虑到旋转数组的特殊情况
//1.把排序数组的前面零个数组搬到最后面
//2.三个下标所对应的值相等:10111,11101,此时只能使用顺序查找法

#include <iostream>
using std::endl;
using std::cout;

int MinInOrder(int *numbers,int index1,int index2)
{
    int min=numbers[index1];
    for(int i=index1+1;i<=index2;i++)
    {
        if(min>numbers[i])
        {
            min=numbers[i];
        }
    }
    return min;
}

int Min(int *numbers,int len)
{
    if(numbers==nullptr || len<=0)
    {
        cout<<"Invalid parameters!"<<endl;
        exit(0);
    }

    int lIndex=0;
    int rIndex=len-1;
    int mIndex=lIndex;//若是旋转为0，则递增，第一个数为最小值
    while(numbers[lIndex]>=numbers[rIndex])
    {
        if(rIndex-lIndex == 1)
        {
            mIndex=rIndex;
            break;
        }

        mIndex=(rIndex+lIndex)/2;
        if(numbers[rIndex]==numbers[mIndex] &&
           numbers[rIndex]==numbers[mIndex])
        {
            return MinInOrder(numbers,lIndex,rIndex);
        }
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
  //  int num[]={1,1,1,0,1};
  //  int num1[]={1,2,3,4,5,6};
    int num2[]={1};
    cout<<Min(num2,6)<<endl;;
    return 0;
}

