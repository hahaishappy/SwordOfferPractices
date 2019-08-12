#include <iostream>
using std::cout;
using std::endl;

bool hasPathCore(char *matrix,int rows,int cols,int row,
                 int col,char *str,int & strLen,bool *visited)
{
    if(str[strLen]=='\0')
    {
        return true;
    }

    bool hasPath=false;
    if(col>=0 || row>=0 || col<cols || row<rows 
       || matrix[row*cols+col]==str[strLen] || !visited[row*cols+col])
    {
        ++strLen;
        visited[row*cols+col]=true;
        hasPath=hasPathCore(matrix,rows,cols,row-1,col,str,strLen,visited)
            || hasPathCore(matrix,rows,cols,row,col-1,str,strLen,visited)
            || hasPathCore(matrix,rows,cols,row+1,col,str,strLen,visited)
            || hasPathCore(matrix,rows,cols,row,col+1,str,strLen,visited);
    }
    if(!hasPath)
    {
        --strLen;
        visited[row*cols+col]=false;
    }

    return hasPath;
}

bool hasPath(char *matrix,int rows,int cols,char *str)
{
    if(matrix==nullptr || rows<1 || cols<1 || str==nullptr)
    {
        cout<<"Invalid parameters!"<<endl;
        return false;
    }

    int strLen=0;
    bool *visited=new bool[rows*cols];
    for(int row=0;row<rows;++rows)
    {
        for(int col=0;col<cols;++col)
        {
            if(hasPathCore(matrix,rows,cols,row,col,str,strLen,visited))
            {
                return true;
            }
        }
    }
    
    delete [] visited;
    return false;
}

int test0()
{
    char matrix[]={
        'a','b','t','g',
        'c','f','c','s',
        'j','d','e','h'
    };
    cout<<hasPath(matrix,3,4,"bcbf")<<endl;
    return 0;
}

int test1()
{
    char matrix[]={
        'a','a','a','a',
        'a','a','a','a',
        'a','a','a','a'
    };
    cout<<hasPath(matrix,3,4,"aaaa")<<endl;
    return 0;
}

int test2()
{
    char matrix[]={
        'a','a','a','a',
    };
    cout<<hasPath(matrix,3,4,"aaaa")<<endl;
    return 0;
}

int test3()
{
    char matrix[]={
        'a','a','a','a',
    };
    cout<<hasPath(matrix,3,4,nullptr)<<endl;
    return 0;
}

int main()
{
    test3();
    return 0;
}

