#include <iostream>
using std::cout;
using std::endl;

bool equal(double a,double b)
{
    if((a-b)>=-0.0000000001 && (a-b)<=0.0000000001)
    {
        return true;
    }
    else
        return false;
}

double PowerCore(double base,double exponent)
{
    double sum=1.0;
    for(int i=1;i<=exponent;++i)
    {
        sum*=base;
    }
    return sum;
}

bool flag=false;
double Power(double base,int exponent)
{
    flag=false;
    if(equal(base,0.0) && exponent<0)
    {
        flag=true;
        return 0.0;
    }
    
    unsigned int absExponent=(unsigned int)exponent;
    if(exponent<0)
        absExponent=(unsigned int)(-exponent);

    double sum=PowerCore(base,absExponent);
    if(exponent<0)
        sum=1.0/sum;

    return sum;
}

int main()
{
    cout<<Power(0,-3)<<endl;
    return 0;
}

