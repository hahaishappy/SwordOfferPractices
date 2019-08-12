#include <stdlib.h>
#include "greedy.h"

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        cout<<"invalid papameters!"<<endl;
        exit(0);
    }
    cout<<"len:"<<*argv[1]<<endl;
    cout<<"maxCutting:"<<maxCutting(atoi(argv[1]))<<endl;

    return 0;
}

