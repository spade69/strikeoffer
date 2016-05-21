#include<iostream>
#include<vector>
#include<string>
using namespace std;


void per_core(string& str,char* begin,vector<string>& result)
{

    if(*begin=='\0')
    {
        result.push_back(str);
    }

    else{

    for(char* p=begin;*p!='\0';p++)
    {

        string bstr;
        bstr.assign(str);

        char tmp=*p;
        *p=*begin;
        *begin=tmp;

        per_core(str,begin+1,result);

        tmp=*p;
        *p=*begin;
        *begin=tmp;


    }

    }//else
}

vector<string> Permutation(string str)
{
    vector<string> result;
    if(str.empty())
        return result;

    char *begin=&str[0];
    per_core(str,begin,result);
    return result;
}

int main()
{
    vector<string> result;
    string a("abc");
    result=Permutation(a);
    vector<string>::iterator iter=result.begin();
    for(;iter!=result.end();iter++)
    {
        cout<<*iter<<endl;
    }
    return 0;
}
