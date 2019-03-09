#include<iostream>
#include<cstdio>
using namespace std;
int mod;
int quickpow(int a,int x)
{
        int ans=1;
        while(x>0)
        {
                if(x&1) ans=a*ans%mod;
                a=a*a%mod;
                x>>=1;
        }
        return ans%mod;

}
int main()
{
        int a,x;
        while(scanf("%d%d%d",&a,&mod,&x)!=EOF)
        {
                if(a==0&&mod==0&&x==0) break;
                printf("%d\n",quickpow(a,x));
        }
        return 0;
}
