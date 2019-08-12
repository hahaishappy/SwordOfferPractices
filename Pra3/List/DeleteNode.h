#pragma once

#include <iostream>
using std::cout;
using std::endl;

struct ListNode
{
    int value;
    ListNode * pNext;
};

void deleteNode(ListNode ** pListHead,ListNode *pToDeleted)
{
    if((*pListHead)==nullptr || pToDeleted==nullptr)
    {
        cout<<"invalid parameters!"<<endl;
        return;
    }
    
    if(pToDeleted->pNext)
    {
        pToDeleted->value=pToDeleted->pNext->value;
        pToDeleted->pNext=pToDeleted->pNext->pNext;
        delete pToDeleted;
        pToDeleted=nullptr;
    }

    //特殊情况一：链表上只有一个节点
    else if((*pListHead)==pToDeleted)
    {
        (*pListHead)->pNext=nullptr;
        delete pToDeleted;
        pToDeleted=nullptr;
    }

    //特殊情况二：要删除的节点为尾节点
    if(pToDeleted->pNext==nullptr)
    {
        ListNode *pCur=(*pListHead);
        while(pCur->pNext!=pToDeleted)
        {
            pCur=pCur->pNext;
        }

        pCur->pNext=nullptr;
        delete pToDeleted;
        pToDeleted=nullptr;
    }
}

