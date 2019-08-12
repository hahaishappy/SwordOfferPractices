#pragma once

#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

template<typename T>
class MyStack
{
public:
    MyStack(void);
    ~MyStack(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    queue<T> q1;
    queue<T> q2;
};

template<typename T>
MyStack<T>::MyStack(void)
{}

template<typename T>
MyStack<T>::~MyStack(void)
{}

template<typename T>
void MyStack<T>::appendTail(const T& node)
{
    q1.push(node);
}


template<typename T>
T MyStack<T>::deleteHead()
{
    if(q1.empty() && q2.empty())
    {
        cout<<"deleteHead():stack is empty!"<<endl;
        exit(1);
    }
    T e;
    if(q2.empty())
    {
        while(q1.size()>1)
        {
            e=q1.front();
            q1.pop();
            q2.push(e);
        }
        e=q1.front();
        q1.pop();
    }
    else if(q1.empty())
    {
        while(q2.size()>1)
        {
            e=q2.front();
            q2.pop();
            q1.push(e);
        }
        e=q2.front();
        q2.pop();
    }
    else//这个条件意味着q1中只有一个元素且是栈的最顶部元素
    {
        e=q1.front();
        q1.pop();
    }
    return e;
}



