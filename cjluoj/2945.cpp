#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int ans[32];
        long long n;
        int i;
        while(scanf("%lld",&n)!=EOF)
        {
                int t=0;
                while(n)
                {
                        ans[t++]=n%2;
                        n/=2;
                }
                for(i=0;i<32-t;i++) printf("0");
                for(i=t-1;i>=0;i--) printf("%d",ans[i]);
                printf("\n");
        }
        return 0;
}
