#pragma once
#include <iostream>
using std::cout;
using std::endl;

struct ListNode
{
    int value;
    ListNode * pNext;
};

void deleteDuplication(ListNode **pListHead)
{
    if(pListHead==nullptr || (*pListHead)==nullptr)
    {
        cout<<"invalid parameters!"<<endl;
        return;
    }

    ListNode *pPreNode=nullptr;
    ListNode *pNode=*pListHead;

    while(pNode)
    {
        if(pNode->value != pNode->pNext->value)
        {
            pPreNode=pNode;
            pNode=pNode->pNext;
        }
        else
        {
            ListNode * pToDeleted=pNode;
            int value=pNode->value;
            while(pNode && pNode->value==value)
            {
                pToDeleted=pNode;
                delete pToDeleted;
                pToDeleted=nullptr;

                pNode=pNode->pNext;
            }

            if(pPreNode && !pNode)
                pPreNode->pNext=nullptr;
            else
                pPreNode->pNext=pNode;
        }

    }
}
