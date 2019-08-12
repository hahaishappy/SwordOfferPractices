#include "Queue2.h"

int main()
{
    MyQueue<int> mq;
    mq.appendTail(1);
    mq.appendTail(2);
    mq.appendTail(3);
    mq.appendTail(4);
    mq.print();
    cout<<mq.deleteHead()<<endl;
    mq.print();
    cout<<mq.deleteHead()<<endl;
    mq.print();
    cout<<mq.deleteHead()<<endl;
    mq.print();
    cout<<mq.deleteHead()<<endl;
    mq.print();
    cout<<mq.deleteHead()<<endl;
    mq.print();

    return 0;
}

