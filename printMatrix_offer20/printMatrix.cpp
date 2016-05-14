#include<iostream>
#include<vector>

using namespace std;

//void printMatrix



void PrintMatrixInCircle(vector<vector<int> > matrix,vector<int>* result,int start)
{
    int columns=matrix[0].size();
    int rows=matrix.size();
    int endX=columns-start-1;
    int endY=rows-start-1;

    //from left to right step1
    for(int i=start;i<=endX;++i)
    {
        int number=matrix[start][i];
       // cout<<number<<endl;
        result->push_back(number);

    }
    //from up to down step 2
    if(start<endY){
        for(int i=start+1;i<=endY;++i)
        {

            int number=matrix[i][endX];
        result->push_back(number);


        }
    }
    //from right to left ,step3
    if(start<endX&&start<endY)
    {
        for(int i=endX-1;i>=start;--i){
            int number=matrix[endY][i];
          result->push_back(number);

        }
    }
    //step 4
    if(start<endX&&start<endY-1)
    {
        for(int i=endY-1;i>=start+1;--i)
        {
            int number=matrix[i][endX];
            result->push_back(number);
        }
    }
}


vector<int> printMatrix(vector<vector<int> > matrix){


    int columns=matrix[0].size();
    int rows=matrix.size();
    vector<int>* result=new vector<int>();

    if(matrix.empty()||matrix[0].empty())
        return *result;
    int start=0;

    while(columns>start*2&&rows>start*2)
    {
    //int columns=matrix[0].size();
    //int rows=matrix.size();
    int endX=columns-start-1;
    int endY=rows-start-1;

    //from left to right step1
    for(int i=start;i<=endX;++i)
    {
        int number=matrix[start][i];
       // cout<<number<<endl;
        result->push_back(number);

    }
    //from up to down step 2
    if(start<endY){
        for(int i=start+1;i<=endY;++i)
        {

            int number=matrix[i][endX];
        result->push_back(number);


        }
    }
    //from right to left ,step3
    if(start<endX&&start<endY)
    {
        for(int i=endX-1;i>=start;--i){
            int number=matrix[endY][i];
          result->push_back(number);

        }
    }
    //step 4
    if(start<endX&&start<endY-1)
    {
        for(int i=endY-1;i>=start+1;--i)
        {

            int number=matrix[i][start];
            result->push_back(number);
        }
    }
    ++start;
    }
    //return NULL;
    return *result;
}


int main()
{

    vector<vector<int> > m(4,vector<int>(0));
    vector<int> show;

    for(int j=0;j<4;j++)
    {
        for(int i=0;i<5;i++ )
            m[j].push_back(i);
    }

    for(int j=0;j<4;j++)
    {
        for(int i=0;i<m[j].size();i++)
        {
            cout<<m[j][i]<< " ";
        }
        cout<<endl;
    }

    show=printMatrix(m);
    cout<<show.size()<<endl;
    for(int k=0;k<show.size();k++)
        cout<<show[k]<<"->" ;

    cout<<endl;
    return 0;

}

