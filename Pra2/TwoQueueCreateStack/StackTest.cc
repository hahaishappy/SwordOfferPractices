#include "Stack.h"

void test(int actual,int execpted)
{
    if(actual==execpted)
        cout<<"passed!"<<endl;
    else
        cout<<"failed!"<<endl;
}

int main()
{
    MyStack<int> ms;
    ms.appendTail(1);
    ms.appendTail(2);
    ms.appendTail(3);

    int e=ms.deleteHead();
    cout<<e<<endl;
    test(e,3);
    
    ms.appendTail(4);

    e=ms.deleteHead();
    cout<<e<<endl;
    test(e,4);

    e=ms.deleteHead();
    cout<<e<<endl;
    test(e,2);

    e=ms.deleteHead();
    
    return 0;
}

