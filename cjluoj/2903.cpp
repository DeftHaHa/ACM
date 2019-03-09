#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<string>
using namespace std;
int main()
{
        int abc,de;
        char s[100];
        string t;
        set<char> S;
        while(cin>>t)
        {
                int c=0;
                int num1,num2,numans;
                for(int i=0;i<t.length();i++) S.insert(t[i]);
                for(int i=111;i<=999;i++)
                {
                        for(int j=11;j<=99;j++)
                        {
                                num1=i*(j%10);num2=i*(j/10);numans=i*j;
                                sprintf(s,"%d%d%d%d%d",i,j,num1,num2,numans);
                                bool flag=true;
                                for(int k=0;k<strlen(s);k++)
                                        if(!S.count(s[k]))
                                        {
                                                flag=false;
                                                break;
                                        }
                                if(flag)
                                {
                                        printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",++c,i,j,num1,num2,numans);
                                        memset(s,0,sizeof(s));
                                }
                        }
                }
                printf("the number of solutions=%d\n",c);
                S.clear();
        }
        return 0;
}
