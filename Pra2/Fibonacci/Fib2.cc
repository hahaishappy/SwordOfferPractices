//斐波拉契数列计算改进版本——避免重复的计算
#include <sys/time.h>
#include <iostream>
using std::endl;
using std::cout;

long long int fab(int n)
{
    int number[]={0,1};
    if(n<2)
        return number[n];

    long long int fabFirst=0;
    long long int fabSecond=1;
    long long int fabNum=0;
    for(int i=2;i<=n;++i)
    {
        fabNum=fabFirst+fabSecond;
        fabFirst=fabSecond;
        fabSecond=fabNum;
    }
    return fabNum;
}

int main()
{
    struct timeval begin,end;
    gettimeofday(&begin,NULL);
    cout<<"fabNum:"<<fab(50)<<endl;
    gettimeofday(&end,NULL);
    cout<<"use time:"<<(end.tv_usec-begin.tv_usec)*1000000
        +end.tv_sec-begin.tv_sec<<endl;
    return 0;
}

