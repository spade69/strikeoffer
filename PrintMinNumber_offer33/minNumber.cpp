#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

string to_string(int val){
    char *a=new char[100] ;
//int 2 string
    sprintf(a,"%d",val);
    string s(a);
    return s;
}

string PrintMinNumber(vector<int> numbers){
    string result;//=new string();
    if(numbers.empty())
    {
        return result;
        cout<<"Error"<<endl;
    }

    //sort the array
    sort(numbers.begin(),numbers.end());

    vector<int>::iterator iter=numbers.begin();

    string s=to_string(*iter);
        iter=iter+1;

        //此处只是比较然后拼接
    for(;iter<numbers.end();iter++){
        //s=to_string(*iter);
        string tmp=to_string(*iter);


        if((s+tmp)<(tmp+s))
            s+=tmp;
        else
            s=tmp+s;
    }
    result=s;
    return result;
}

int main(){
    int a[3]={3,32,321};
    vector<int> num(a,a+3);
    string s;
    s=PrintMinNumber(num);
    cout<<s<<endl;
    return 0;
}
