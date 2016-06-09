#include<iostream>
#include<vector>
using namespace std;
/************
 *Get the ouccur times of target number:K
input : Array , Target K
return: times
 *Sorted Array : 1,2,3,3,3,4,5
 Because it is sorted ,so 3,3,3 must occur like this way.
 1,2,3,4,3, that is not sorted. So we just need to find the
 first K and the last K
 *
 * Author :Jason
 * Date:2016/06/09
 * ********************/


int GetFirstIndex(vector<int>& data,int k,int start,int end){
    if(start>end)
        return -1;
    int mid=(end+start)/2;
    if(data[mid]==k){
        if((mid>0&&data[mid-1]!=k)||mid==0)
            return mid;
        else
            end=mid-1;
    }
    else if(data[mid]>k){
        end=mid-1;
    }
    else{
        start=mid+1;
    }
    return GetFirstIndex(data,k,start,end);
}

int GetLastIndex(vector<int>& data,int k,int start,int end){
    if(start>end)
        return -1;
    int mid=(end+start)/2;
    int len=data.size();
    if(data[mid]==k){
        if((mid<(len-1)&&data[mid+1]!=k)||mid==(len-1))
            return mid;
        else
            start=mid+1;
    }
    else if(data[mid]<k){
        start=mid+1;
    }
    else{
        end=mid-1;
    }
    return GetLastIndex(data,k,start,end);
}


int GetNumberK(vector<int> data,int k){
  if(data.empty())
      return 0;
  int number=0;
  int len=data.size();
  int first=GetFirstIndex(data,k,0,len-1);
  int last=GetLastIndex(data,k,0,len-1);

  if(first!=-1&&last!=-1)
      number=last-first+1;

  return number;
}

int main(){
    int a[8]={1,2,3,3,3,3,4,5};
    vector<int> vec(a,a+8);
    int count=0;
    count=GetNumberK(vec,3);
    cout<<count<<endl;
    return 0;
}
