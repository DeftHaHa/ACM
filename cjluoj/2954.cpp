#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int Next[10000005];
char s[1000005];
int main()
{

        memset(s,0,sizeof(s));
        while(scanf("%s",s)!=EOF)
        {
                int match=-1;
                Next[0]=-1;
                int l=strlen(s);
                for(int i=1;i<l;i++)
                {
                        while(match>=0&&s[match+1]!=s[i])
                        {
                                match=s[match];
                        }
                        if(s[match+1]==s[i])
                                match++;
                        Next[i]=match;
                }
                printf("%d\n",l/(l-Next[l-1]-1));
                memset(s,0,sizeof(s));
        }
        return 0;
}
