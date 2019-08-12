#pragma once

#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;
using std::ostream;

template<typename T>
class MyQueue
{
public:
    MyQueue(void);
    ~MyQueue(void);

    void appendTail(const T& element);
    T deleteHead();

    void print();
private:
    stack<T> s1;
    stack<T> s2;
};

template<typename T>
MyQueue<T>::MyQueue()
{}

template<typename T>
MyQueue<T>::~MyQueue()
{}

template<typename T>
void MyQueue<T>::appendTail(const T& node)
{
    s1.push(node);
}

template<typename T>
T MyQueue<T>::deleteHead()
{
    if(s1.empty() && s2.empty())
    {
        cout<<"deleteHead():queue is empty!"<<endl;
    }
    T e;
    if(s2.empty())
    {
        while(!s1.empty())
        {
          e=s1.top();
          s1.pop();
          s2.push(e);
        }
    }

    T head=s2.top();
    s2.pop();
    return head;
}

//如果改变了栈的策略，那么以前的测试程序也将重新改写
template<typename T>
void MyQueue<T>::print()
{
    if(s1.empty() && s2.empty())
    {
        cout<<"Print():queue is empty!"<<endl;
        exit(1);
    }
    T e;
    stack<T> s4;
    while(!s2.empty())
    {
        e=s2.top();
        s2.pop();
        s4.push(e);
    }
    while(!s4.empty())
    {
        e=s4.top();
        s4.pop();
        cout<<e<<" ";
        s2.push(e);
    }
    stack<T> s3;
    while(!s1.empty())
    {
        e=s1.top();
        s1.pop();
        cout<<e<<" ";
        s3.push(e);
    }
    cout<<endl;
    while(!s3.empty())
    {
        e=s3.top();
        s3.pop();
        s1.push(e);
    }
}

