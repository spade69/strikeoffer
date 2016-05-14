#include<iostream>
#include<vector>

using namespace std;

void printNumber(int d)
{
    cout<<d<<endl;
}

void PrintMatrixInCircle(int **number,int columns,int rows,int start)
{
    int endX=columns-start-1;
    int endY=rows-start-1;

    //from left to right step1
    for(int i=start;i<=endX;++i)
    {
        int number=numbers[start][i];
        printNumber( number);

    }
    //from up to down step 2
    if(start<endY){
        for(int i=start+1;i<=endY;++i)
        {
            int number=numbers[i][endX];
            printNumber(number);
        }
    }
    //from right to left ,step3
    if(start<endX&&start<endY)
    {
        for(int i=endX-1;i>=start;--i){
            int number=numbers[endY][i];
            printNumber(number);
        }
    }
    //step 4
    if(start<endX&&start<endY-1)
    {
        for(int i=endY-1;i>=start+1;--i)
        {
            int number=numbers[i][endX];
            printNumber(number);
        }
    }
}

void PrintMatrixClockwisely(int** numbers,int columns,int rows)
{
    if(numbers==NULL||columns<=0||rows<=0)
        return;
    int start=0;
    while(columns>start*2&&rows>start*2)
    {
        PrintMatrixInCircle(numbers,columns,rows,start)
            ++start;
    }

}

/*
vector<int> printMatrix(vector<vector<int>> matrix){

}
*/
