#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
        char c;
        bool flag=false;
        while(~scanf("%c",&c))
        {
                if(c=='!') {flag=!flag;continue;}
                else if(c=='\n') flag=false;
                if(flag)
                {
                        if(c>='A'&&c<='Z') c+=32;
                        else if(c>='a'&&c<='z') c-=32;
                }
                printf("%c",c);
        }
        return 0;
}
