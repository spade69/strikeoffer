#include<iostream>
#include<vector>
using namespace std;

bool CheckMoreThanHalf(vector<int> numbers,int index){
    vector<int>::iterator iter=numbers.begin();
    int times=0;
    for(;iter<numbers.end();iter++)
    {
        if(*iter==index)
            times++;
    }
    bool result=true;

    if(times*2<=numbers.size())
        result=false;

    return result;
}

int MoreThanHalf(vector<int> numbers){
    if(numbers.empty()) //if judge int* array includeing NULL & Length
        return 0;
    vector<int>::iterator iter=numbers.begin();
    int times=0;
    int index;
    for(;iter<numbers.end();iter++){
        if(times==0) //In one loop just processing one thing,so if elseif else
        {
            index=*iter;
            times++;
        }
        else if(index==*iter)
        {
            times++;
        }
        else
        {
            times--;
        }


    }
    if(!CheckMoreThanHalf(numbers,index))
        return 0;
    return index;
}


int main()
{
    int a[9]={1,2,3,2,2,2,5,4,2};
    vector<int> numbers(a,a+9);
    bool result=false;
    int index;
    //result=CheckMoreThanHalf(numbers,2);
    index=MoreThanHalf(numbers);
    cout<<index<<endl;
    return 0;
}
