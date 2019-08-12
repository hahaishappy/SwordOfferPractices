#include <iostream>
using std::endl;
using std::cout;

int RandomInRange(int start,int end)
{

}

int partition(int data[],int len,int start,int end)
{
    if(data==nullptr || len<=0 || start<0 || end>=len)
    {
        exit(1);
    }

    int index=RandomInRange(start,end);
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

