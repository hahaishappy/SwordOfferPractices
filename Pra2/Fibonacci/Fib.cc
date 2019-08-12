#include <sys/time.h>
#include <iostream>
using std::endl;
using std::cout;

int fab(int n)
{
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fab(n-1)+fab(n-2);
}


int main()
{
    struct timeval begin,end;
    gettimeofday(&begin,NULL);
    fab(50);
    gettimeofday(&end,NULL);
    cout<<"use time:"<<(end.tv_usec-begin.tv_usec)*1000000
        +end.tv_sec-begin.tv_sec<<endl;
    return 0;
}

