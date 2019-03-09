#include<stdio.h>
int main()
{
        int N;
        char ch;
        int i,j;
        int sum;
        int n;
        while(scanf("%d",&N)!=EOF)
        {
                i=1;sum=1;
                if(N==1)
                {
                        printf("*\n0\n");
                        continue;
                }
                else if(N==0)
                {
                        printf("0");
                        return 0;
                }
                while(sum<=N)
                {
                       i+=2;
                       sum+=i*2;
                }
                sum-=i*2;
                n=(i+1)/2-1;
                for(i=n;i>=1;i--)
                {
                        for(j=i;j<n;j++)
                                printf(" ");
                        for(j=0;j<2*i-1;j++)
                                printf("*");
                        printf("\n");
                }
                for(i=2;i<=n;i++)
                {
                        for(j=i;j<n;j++)
                                printf(" ");
                        for(j=0;j<2*i-1;j++)
                                printf("*");
                        printf("\n");
                }
                printf("left:%d\n",N-sum);
        }

        return 0;
}
