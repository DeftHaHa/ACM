#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        int T;
        scanf("%d",&T);
        long long p;
        while(T--)
        {
                long long n;
                long long d=6;
                scanf("%I64d",&n);
                bool flag=false;
                for(long long i=7;i<=n;i+=d)
                {
                        if(i==n) flag=true;
                        d+=6;
                }
                if(flag) printf("YES\n");
                else printf("NO\n");

        }

        return 0;
}
