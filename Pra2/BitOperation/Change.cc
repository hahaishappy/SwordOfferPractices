#include <iostream>
using std::endl;
using std::cout;

int changeNum(int num1,int num2)
{
    int num=num1^num2;

    int count=0;
    while(num)
    {
        ++count;
        num=num&(num-1);
    }
    return count;
}

int main()
{
    cout<<changeNum(10,13)<<endl;
    return 0;
}

