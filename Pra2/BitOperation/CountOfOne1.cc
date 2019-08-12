#include <iostream>
using std::cout;
using std::endl;

int numberOf1(int num)
{
    int count=0;
    unsigned int flag=1;
    while(flag)
    {
        if(num & flag)
        {
            count++;
        }
        flag=flag<<1;
    }
    return count;
}

int main()
{
    cout<<numberOf1(3)<<endl;
    return 0;
}

