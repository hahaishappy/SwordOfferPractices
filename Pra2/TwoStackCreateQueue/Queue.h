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
    int length;
};

template<typename T>
MyQueue<T>::MyQueue()
{
    length=0;
}

template<typename T>
MyQueue<T>::~MyQueue()
{}

template<typename T>
void MyQueue<T>::appendTail(const T& node)
{
    s1.push(node);
    length++;
}

template<typename T>
T MyQueue<T>::deleteHead()
{
    T e,head;
    if(s1.empty())
    {
        cout<<"queue is empty!"<<endl;
        exit(0);
    }
    while(!s1.empty())
    {
        e=s1.top();
        s1.pop();
        s2.push(e);
    }
    head=s2.top();
    while(!s2.empty())
    {
        e=s2.top();
        s2.pop();
        s1.push(e);
    }
    length--;
    return head;
}

template<typename T>
void MyQueue<T>::print()
{
    if(s1.empty())
    {
        cout<<"Print():s1 is empty!"<<endl;
        exit(1);
    }
    stack<T> s3;
    T e;
    for(int i=0;i<length;i++)
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

