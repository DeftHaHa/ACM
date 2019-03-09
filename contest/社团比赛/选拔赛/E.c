#include<stdio.h>

int main()
{
        int a[100000];
        int C,N;
        int ans;
        int i,k;
        scanf("%d",&C);
        while(C--)
        {
                ans=0;
                scanf("%d",&N);
                scanf("%d",&a[0]);
                for(i=1;i<=N-1;i++)
                {
                        scanf("%d",&a[i]);
                        k=a[i]-a[i-1];
                        if(k>ans) ans=a[i]-a[i-1];
                }
                printf("%d\n",ans);
        }
        return 0;
}
