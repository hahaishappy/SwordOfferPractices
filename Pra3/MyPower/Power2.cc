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

//改进连乘的效率
double PowerCore(double base,unsigned int exponent)
{
    if(exponent==0)
        return 1;
    if(exponent==1)
        return base;

    double sum=PowerCore(base,exponent>>1);
    sum*=sum;

    if((exponent&0x1) == 1)
        sum*=base;
    
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
    cout<<Power(5,3)<<endl;
    return 0;
}

