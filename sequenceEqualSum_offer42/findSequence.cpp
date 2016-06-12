#include<iostream>
#include<vector>
using namespace std;

/***************************
 *Find a continuous Sequence that sum equals to the given number
 *input: a given number "sum"
 *output:
 *return : all sequence that  of num equals to sum
Method& thinking:
  eg: given sum 9
    if(curr<sum)
    {1,2} -->{1,2,3}-->{1,2,3,4}
    else if(curr>sum)
    {1,2,3,4}-->{2,3,4}
    then find euals to 9. store it.
 * Author Jason
 * Date 2016/06/12
 * **********************************/

//Technique: because the sum compared with last time only
//add a number or remove a number, so we should store it every time and
//avoid unnecessary calculation

vector<vector<int> > FindContinuousSequence(int sum)
{
    vector<vector<int> > result;
    if(sum<3)
        return result;
    int small=1,big=2;
    int curr=0;
    int middle=(1+sum)/2;//if sum==9 middle=5.
    //intialize
    curr=small+big;

    while(small<big){

       if(curr==sum){
           vector<int> tmp;
            for(int i=small;i<=big;i++){
                tmp.push_back(i);
            }
            result.push_back(tmp);
            big++;
            curr+=big;
        }
        else if(curr<sum){
            big++;
            curr+=big;
        }
        else{
            curr-=small;
            small++;
        }

    }
    return result;
}

int main(){
    int sum=9;
    vector<vector<int> > result;
    result=FindContinuousSequence(sum);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


