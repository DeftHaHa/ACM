#include<stdio.h>
int main()
{
        int ans;
        int n;
        while(1)
        {
                scanf("%d",&n);
                if(n==-1) break;
                ans=0;
                while(n>0)
                {
                        ans++;
                        n/=10;
                }
                printf("%d\n",ans);
        }
        return 0;
}
