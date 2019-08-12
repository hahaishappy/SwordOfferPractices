#include <iostream>
using std::endl;
using std::cout;

int getDisSum(int number)
{
    int sum=0;
    while(number>0)
    {
        sum+=number%10;
        number=number/10;
    }
    return sum;
}

bool check(int limits,int rows,int cols,int row,int col,bool *visited)
{
    if(row>=0 && row<rows && col>=0 && col<cols
       && getDisSum(row)+getDisSum(col)<=limits
       && !visited[row*cols+col])
        return true;

    return false;
}

int movingCountCore(int limits,int rows,int cols,
                    int row,int col,bool *visited)
{
    int count=0;
    if(check(limits,rows,cols,row,col,visited))
    {
        cout<<row<<","<<col<<endl;
        visited[row*cols+col]=true;
        count=1+movingCountCore(limits,rows,cols,row-1,col,visited)
            +movingCountCore(limits,rows,cols,row+1,col,visited)
            +movingCountCore(limits,rows,cols,row,col-1,visited)
            +movingCountCore(limits,rows,cols,row,col+1,visited);
    }

    return count;
}

int movingCount(int limits,int rows,int cols)
{
    if(limits<=0 || rows<=0 || cols<=0)
    {
        cout<<"Invalid parameters!"<<endl;
        return -1;    
    }

    bool * visited=new bool[cols*rows];
    for(int i=0;i<cols*rows;++i)
    {
        visited[i]=false;
    }

    int count=movingCountCore(limits,rows,cols,0,0,visited);
    
    delete [] visited;
    return count;
}

int test0()
{
    cout<<movingCount(18,100,100)<<endl;
    return 0;
}

int main()
{
    test0();
    return 0;
}

