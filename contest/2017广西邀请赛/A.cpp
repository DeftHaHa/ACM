#include<iostream>
#include<cstdio>
using namespace std;
long long quickpow(long long a,long long b)
{
        long long ans=1;
        while(b>0)
        {
                if(b&1) ans*=a;
                a=a*a;
                b>>=1;
        }
        return ans;
}
int main()
{
        long long n;
        while(scanf("%lld",&n)!=EOF)
        {
                int tot=0;
                for(long long i=1;i<=15;i++)
                {
                        if(quickpow(i,i)<=n) tot++;
                        else break;
                }
                printf("%d\n",tot);
        }
        return 0;
}
