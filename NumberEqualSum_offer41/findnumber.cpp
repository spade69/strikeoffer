#include<iostream>
#include<vector>
using namespace std;
/***************************
 *Find a pair of num in sequence that sum equals to the given number
 *input: a sorted sequence vector<int> "array" , given number "sum"
 *output:
 *return : arbitrary pair of num equals to sum
 * Author Jason
 * Date 2016/06/12
 * **********************************/

vector<int> FindNumbersWithSum(vector<int> array,int sum){
    vector<int> result;
    if(array.size()<2||array.empty())
        return result;
    int len= array.size();
    int head=0;
    int tail=len-1;
    int curr=0;
    while(head<tail){
        curr=array[head]+array[tail];
        if(sum==curr){
            result.push_back(array[head]);
            result.push_back(array[tail]);
            break;
        }
        else if(curr>sum){
            tail--;
            //curr=array[]
        }
        else{
            head++;
        }

    }

    return result;
}


int main(){
    int a[6]={1,2,4,7,11,15};
    vector<int> vec(a,a+6);
    vector<int> result;
    result=FindNumbersWithSum(vec,15);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
