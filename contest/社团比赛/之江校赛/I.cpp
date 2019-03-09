#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<ctime>
using namespace std;
bool jg[10000005];
int main()
{
        int n;
        int t=1;
        int c=1;
        int i,j;
        int p[500005];
        memset(jg,true,sizeof(jg));
        for(i=2;i<=sqrt(10000000);i++)
        {
                if(jg[i]==true)
                {
                        for(j=i*2;j<10000000;j+=i)
                        {
                                jg[j]=false;
                        }
                }
        }
        for(i=2;i<10000000;i++)
                {
                        if(jg[i]==true)
                        {
                                p[t++]=i;//printf("*%d",p[t]);
                        }
                        if(t==500001) break;
                }
        while(1)
        {
                scanf("%d",&n);
                if(n==0) return 0;
                printf("Case %d: %d\n",c,p[n]);
                c++;
        }
        return 0;
}
