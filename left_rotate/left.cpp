#include<iostream>
#include<string>
#include<string.h>
using namespace std;


/***************************
*Left rotate a sentence. Move n bits of the front of the string to the tail of it.
*input: a string and given number that means how many bits you want to rotate.
*output:
*return :a left-rotated sentence(string)
Method& thinking:
eg: abcdef n=2
Reverse  ab then reverse cdef
and then reverse whole sentence
* Author Jason
* Date 2016/06/14
* **********************************/

void Reverse(char* b,char* e)
{
    if(b==NULL||e==NULL)
        return;

    while(b<e)
    {
        char t=*b;
       *b=*e;//assign *e to *b then b++
        *e=t;//assign t to *e then e--
        b++,e--;
    }
}



string LeftRotateString(string str,int n){
    string s;
    int len=str.length();//len is not including '\0'!!
    if(len<n||len<1)
        return s;
    if(len==n)
        return str;// return itself

    char *p=&str[0];
    char* b=p;//first part of string
    char* e=p+n;//second part of string
    int lenB=len-n;
    Reverse(b,b+n-1);
    Reverse(e,e+lenB-1);
    Reverse(p,p+len-1);
    //b=e=&str[0];//recover
    cout<<str<<endl; //.uoy kcuf i
   return str;
}

int main(){
    string b("abcdef");
    //string a("i fuck you.");
    string rb=LeftRotateString(b,2);
    //string ra=LeftRotateString(a,3);
    //cout<<ra<<endl;
    cout<<rb<<endl;
    return 0;
}
