#include<stdio.h>
int main()
{
        int N;
        int i,j,k,sum;
        while(scanf("%d",&N)!=EOF)
        {
                sum=0;
                for(i=1;i<=N;i++)
                {
                        k=1;
                        for(j=1;j<=i;j++)
                                k*=j;
                        sum+=k;
                }
                printf("%d\n",sum);
        }

        return 0;
}
