#include <iostream>
using std::cout;
using std::endl;

void SortAges(int ages[],int len)
{
    if(ages==nullptr || len<=0)
        return;

    const int oldestAge=99;
    int AgeCount[oldestAge+1];

    for(int i=0;i<=oldestAge;i++)
    {
        AgeCount[i]=0;
    }

    for(int i=0;i<len;i++)
    {
        int age=ages[i];
        if(age<0 || age>oldestAge)
            return;

        ++AgeCount[age];
    }

    //在这里打印出AgeCount的键值和值
    for(int i=0;i<=oldestAge;i++)
    {
        cout<<i<<":"<<AgeCount[i]<<endl;
    }

    //年龄出现了几次，便在数组中设置几次年龄
    int index=0;
    for(int i=0;i<=oldestAge;i++)
    {
        for(int j=0;j<AgeCount[i];j++)
        {
            ages[index]=i;
            index++;
        }
    }
}


int main()
{
    int age[]={23,23,45,45,6,6,78,90,6,8};
    SortAges(age,10);
    for(auto c:age)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}

