#include "DeleteReapet.h"

int testReapet()
{

    ListNode *n1;
    n1->value=1;
    ListNode *n2;
    n2->value=1;
    ListNode *n3;
    n3->value=2;
    ListNode *n4;
    n4->value=2;
    ListNode *n5;
    n5->value=3;
    ListNode *n6;
    n6->value=3;
    n1->pNext=n2;
    n2->pNext=n3;
    n3->pNext=n4;
    n4->pNext=n5;
    n5->pNext=n6;

    deleteReapet(&n1);
    return 0;
}


int main()
{
    testReapet();
    return 0;
}

