#include <iostream>
using std::cout;
using std::endl;

bool isIntegerOfTwo(int num)
{
    if((num&(num-1))==0)
        return true;
    else
        return false;
}

int main()
{
    cout<<isIntegerOfTwo(3)<<endl;
    return 0;
}

