#include<stdio.h>
int main()
{
        int T,ans;
        int n;
        int i;
        scanf("%d",&T);
        while(T--)
                {
                        ans=0;
                        scanf("%d",&n);
                        for(i=0;i<=n;i++)
                                ans+=i*i*i;
                                printf("%d\n",ans);
                }
        return 0;
}
