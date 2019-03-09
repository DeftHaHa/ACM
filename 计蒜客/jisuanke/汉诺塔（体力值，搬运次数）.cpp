#include<iostream>
#include<cstdio>
using namespace std;
long long h(long long now,long long n);
long long a[65];
int main()
{
        long long n;
        long long c,p;
        a[0]=1;
        for(long long i=1;i<61;i++)
                a[i]=a[i-1]*2;
        while(scanf("%lld",&n)!=EOF)
        {
                c=a[n]-1;
                p=h(n,n);
                printf("%lld %lld\n",c,p);
        }
        return 0;
}
long long h(long long now,long long n)
{
        if(now==0) return 0;
        else return h(now-1,n)+a[n-now]*now;
}
