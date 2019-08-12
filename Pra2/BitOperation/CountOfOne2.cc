#include <iostream>
using std::cout;
using std::endl;

int numberOf1(int num)
{
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
    cout<<numberOf1(3)<<endl;
    return 0;
}

