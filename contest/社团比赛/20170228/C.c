#include<stdio.h>
int main()
{
        int T;
        int  n;
        long long a;
        int b;
        long long  ans;
        scanf("%d",&T);
        while(T--)
        {
                ans=0;a=0;b=0;
                scanf("%d",&n);
                while(n--)
                {
                        scanf("%lld%d",&a,&b);
                        if(b==0) continue;
                        else if(a>ans) ans=a+b;
                        else ans+=b;
                }
                printf("%lld\n",ans);
        }
        return 0;
}
