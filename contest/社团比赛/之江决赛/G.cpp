#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long mypow(long long a,long long b)
{
        long long ans=1;
        while(b)
        {
                if(b&1) ans=(ans*a)%1000000007;
                b>>=1;
                a=(a*a)%1000000007;
        }
        return ans;
}
int main()
{
        long long T;
        long long n;
        long long yushu;
        long long mo=1000000007;
        scanf("%lld",&T);
        while(T--)
        {
                scanf("%lld",&n);
                if(n==1)
                {
                        printf("1\n");
                        continue;
                }
                yushu=n%3;
                if(yushu==2)
                        printf("%lld\n",mypow(3,n/3)*2%mo);
                else if(yushu==1)
                        printf("%lld\n",mypow(3,n/3-1)*4%mo);
                else if(yushu==0)
                        printf("%lld\n",mypow(3,n/3)%mo);
        }
        return 0;
}
