#include<stdio.h>
int main()
{
        int ans=0;
        int n;
        scanf("%d",&n);
        while(n>0)
        {
                ans++;
                n/=10;
        }
        printf("%d",ans);
        return 0;
}
