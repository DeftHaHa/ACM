#include<stdio.h>
int main()
{
        int i,j;
        int n;
        int tot;
        while(scanf("%d",&n)!=EOF)
        {
                tot=0;
                for(i=1;i<=n;i++)
                {
                        for(j=i;j<n;j++)
                                printf(" ");
                        for(j=0;j<i*2-1;j++)
                        {
                                printf("*");
                                tot++;
                        }
                        printf("\n");
                }
                printf("stars:%d\n",tot);
        }
        return 0;
}