#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*?************
Function：Get the least k num and return them

input: a group of numbers ,and k .
output:  print  the k least num.
return : k numbers

Author:Jason
Version:1.0
Date:2016/05/25

Boundary：
1.vector is empty , number less than k.,or k=0
2.find the least k number. if exist equal nums?
3.

solution1:
 Using the partition of quick sort and return.

Solution2:
Using a binary tree or red-black tree to store a
group of numbers that size is k.

thinkiing: 1.if the numbers in this container less than k,then just add it
2.if numbers meet the limit k,we  compare this number with the max num in
container. If less than,then swap, otherwise do nothing.



逻辑框架不用动，解耦! 提高代码重用性
********/

vector<int> GetLeastNumbers(vector<int>& input,int k){
    vector<int> result;
    if(k<1||input.size()<k)
    {
        cout<<"You input an illeagal k or your numbers are less than k!"<<endl;
        return result;
    }

    vector<int>::iterator iter=input.begin();
    multiset<int> tmp;
    //tmp.insert(100);


    for(;iter!=input.end();iter++){
        if(tmp.size()<k||k==1)
        {
            tmp.insert(*iter);
        }
        else{
     multiset<int>::iterator itx=tmp.end();
            if(*iter<=*(itx--))
            {
                cout<<*iter<<endl;
             // tmp.erase(tmp.size()-1); this is wrong?,so it means size() won't change?
                tmp.erase(itx);
                tmp.insert(*iter);
            }
        }

    }
    multiset<int>::iterator iter2=tmp.begin();
    int i=0;
    while(i<k){
       result.push_back(*iter2);
       i++;
       iter2++;
    }
    return result;
}


int main(){
    int a[8]={4,5,1,6,2,7,3,8};
    multiset<int> test(a,a+8);
    vector<int> vec1(a,a+8);
    vector<int> result;
    /*
    multiset<int>::iterator iter=test.begin();
    for(;iter!=test.end();iter++){
        cout<<*iter<<" ";
    }*/
    int k=2;
    result=GetLeastNumbers(vec1,k);
    for(vector<int>::iterator iter1=result.begin();iter1!=result.end();iter1++)
    {
        cout<<*iter1<<" ";
    }
    cout<<endl;

    return 0;
}
