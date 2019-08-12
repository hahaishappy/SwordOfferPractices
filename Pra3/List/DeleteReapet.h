#pragma once

#include <iostream>
using std::cout;
using std::endl;

struct ListNode
{
    int value;
    ListNode * pNext;
};

void deleteReapet(ListNode ** pListHead)
{
    if((*pListHead)==nullptr)
    {
        cout<<"invalid parameters!"<<endl;
        return;
    }

    ListNode *pNode=*pListHead;
    ListNode *pCur=(*pListHead)->pNext;

    while(pNode!=nullptr)
    {
        if(pNode->value != pCur->value)
        {
            pCur=pCur->pNext;
            pCur->value=pNode->value;
        }
        
        pNode=pNode->pNext;
    }
}
