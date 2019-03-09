#include<stdio.h>
int main()
{
        int n,i;
        while(1)
        {
                scanf("%d",&n);
                if(n==0) return 0;
                else if(n==1) printf("NO\n");
                else
                {
                        for(i=2;i<n;i++)
                        if(n%i==0) break;
                        if(i>=n) printf("YES\n");
                        else printf("NO\n");
                }
        }
        return 0;
}
