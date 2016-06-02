#include<iostream>
#include<string.h>

using namespace std;

/*********
 *
 *
 *Author Jason
*Date 2016/06/02
 * *********/

int FirstNotRepeatingChar(string str)
{
    //int len=strlen(str);
    int len=str.length();
    if(len<1||len>10000)
    {
        cout<<"empty string or your length>10000"<<endl;
        return -1;
    }

    //define a key-value array(hash map)
    //标准ASCII 是128 个字符,但字符char是8位所以256, secure for insurance
    int hash[256]={0};//这种初始化方式是否合理，还是用memset?,sizeof可以求数组长度
    //memset(hash,0,sizeof(hash));

    int first=-1;

    for(int i=0;i<len;i++){
        hash[str[i]]++;
    }

    for(int i=0;i<len;i++)
    {
        if(hash[str[i]]==1)
        {
            first=i;
            break;
        }

    }

    return first;
}

int main(){
    string s="iloveyoubaby";
    int result;
    result=FirstNotRepeatingChar(s);
    cout<<result<<endl;
    return 0;
}
