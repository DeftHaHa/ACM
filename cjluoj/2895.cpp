#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        char s;
        while(scanf("%c",&s)!=EOF)
        {
                if(s==' '||s==','||s=='\n') printf("%c",s);
                else
                {
                        printf("%c",s-1);
                }
        }
        return 0;
}
