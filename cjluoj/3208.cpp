#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool ans[100000005];
int main()
{
        int a,b;
        int n;
        int num=2;
        a=b=1;
        int i;
        memset(ans,false,sizeof(ans));
        ans[2]=true; int x=1;
        for(i=2;num<=100000000;i++)
        {
                num+=3;
                if((i-1)%4==0) num-=4;
                ans[num]=true;
        }
        while(scanf("%d",&n)!=EOF)
        {
                if(n==0) break;
                bool flag=false;
                int tot=0;
                if(ans[n])
                {
                        for(i=2;i<=n;i++)
                        {
                                if(ans[i]) tot++;
                        }
                        if((tot-1)%4==0) tot--;
                        else if(ans[n+1]) tot++;
                        printf("%d\n",tot);
                }
                else printf("you are kidding me!\n");
        }
        return 0;
}
