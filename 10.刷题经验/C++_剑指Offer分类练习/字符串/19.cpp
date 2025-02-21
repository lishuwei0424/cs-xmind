/*
// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
*/

#include <iostream>
using namespace std;

bool matchCore(const char* str,const char* pattern);
bool match(const char* str,const char* pattern)
{
    if(str==NULL || pattern==NULL)
        return false;

    return matchCore(str,pattern);
}

bool matchCore(const char* str,const char* pattern)
{
    if(*str=='\0' && *pattern=='\0')
        return true;

    if(*str!='\0' && *pattern=='\0')
        return false;
    
    //str:abc pattern: abs
    //str: abc pattern: .cd
    if(*str==*pattern || (*pattern=='.' && *str!='\0'))
        return matchCore(str+1,pattern+1);
    

    //str: abc pattern: a*c
    if(*(pattern+1)=='*')
    {
         if(*pattern==*str || (*pattern=='.' && *str!='\0'))
         {
             return matchCore(str+1,pattern+2)//abc  .*d
               || matchCore(str+1,pattern) //abc, a*d
               || matchCore(str,pattern+2);//abc .*d 忽略 .*


         }

         else
         {
             matchCore(str,pattern+2);//abc .*d 忽略 .*
         }
         
    }

    return false;
 }
int main()
{   

    const char* str="abc";
    const  char* pattern="abc";
    bool result=match(str,pattern);

    cout<<result<<endl;

    return 0;

}