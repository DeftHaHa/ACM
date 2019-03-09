#include<stdio.h>
#include<string.h>
int main()
{
        int n;
        int k[11]={0},t;
        int T;
        int i,j;
        int dp[10][9];
        memset(dp,1,sizeof(dp));
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d",&n);
                t=1;i=0;
                while(n!=0)
                        {
                                k[i]=n%10;
                                n/=10;
                                t++;
                                i++;
                        }
                for(i=1;i<t;i++)
                {
                        for(j=k[i+1];j<=9;j++)
                        {
                                dp[i][j]+=dp[i-1][j];
                        }
                }
                printf("%d",dp[t-1][k[t-2]]);
        }
        return 0;
}
