#include<stdio.h>
#include<string.h>
int main()
{
        int N;
        int dp[15][14];
        int T;
        int i,j,k;
        scanf("%d",&T);
        memset(dp,0,sizeof(dp));
        for(i=0;i<=9;i++)
                dp[1][i]=1;
        for(i=1;i<=10;i++)
        {
                for(j=0;j<=9;j++)
                {
                        for(k=j;k<=9;k++)
                        {
                                dp[i][j]+=dp[i-1][k];
                        }
                }
        }printf("%d",dp[2][2]);
        int m,n[15]={0};
        long long ans=0;
        while(T--)
        {
                scanf("%d",&N);
                if(N<10)
                        printf("%d\n",N);
                else
                {
                        i=1;m=0;
                        while(N!=0)
                        {
                                n[i++]=N%10;
                                N/=10;
                                m++;
                        }
                        ans=





                        printf("%lld\n",ans);
                }
        }
        return 0;
}
