#include<iostream>
#include<string.h>
using namespace std;

bool isNumeric(char* string)
{
   char *p=string;
   int len=strlen(string);
   int count[4]={0};

   while(*p!='\0'){
       if(!((*p>='0'&&*p<='9')||*p=='+'||*p=='-'||*p=='.'||*p=='e'||*p=='E'))
            return false;
        if(*p=='e'||*p=='E'){
            char *temp=p;
            *temp-=32;
            count[0]++;
            if(count[0]>1)
                return false;
            if(*p==string[len-1])
                return false;
            if(*temp==string[0]){//if first
                return false;
            }
            else{
                if(*(temp+1)>='0'&&*(temp+1)<='9'
                        ||*(temp-1)>='0'&&*(temp-1)<='9')
                    return true;
                else
                    return false;

            }

        }
        if(*p=='+'||*p=='-'){
            if(*p=='+'){
                count[1]++;
                if(count[1]>1)
                    return false;
            }
            if(*p=='-'){
                count[2]++;
                if(count[2]>2)
                    return false;
            }
            if(p!=string){
               if(!(*(p-1)=='E'||*(p-1)=='e'))
                   return false;


            }
        }

        if(*p=='.')
        {
            count[3]++;
            if(count[3]>1)
                return false;
            if(*p==string[0])//||*p==string[len-1]) why legal?
                return false;
        }

        p++;

   }
   return true;
}

bool isNumeric(char* string)
{
   char *p=string;
   int len=strlen(string);
   //int count[4]={0};
   int i=0,dot=0,nume=0;

   if(len==0)
       return true;
   if(string[0]=='+'||string[0]=='-')
       i++;
   while(i<len){
       if(string[i]>='0'&&string[i]<='9')
           i++;
       else if(string[i]=='.'){
           if(nume>0)
               return false;
           dot++;
           i++;
       }
       else if(string[i]=='e'||string[i]=='E'){
           nume++;
           i++;
           if(string[i]=='\0')
               return false;
           if(string[i]=='-'||string[i]=='+')
               i++;

       }
       else
           return false;
   }
   if(dot>1||nume>1)
       return false;
   return true;
}



int main(){
    string s="+100";
    return 0;
}

