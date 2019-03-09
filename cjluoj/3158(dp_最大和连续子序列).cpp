#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        int a[100005];
        int i;
        int T;
        int N;
        while(cin>>T)
        {
                int c=0;
                while(T--)
                {

                        cin>>N;
                        for(i=0;i<N;i++) cin>>a[i];
                        int ans=0xc0c0c0c0,ans1=1,ans2=1;
                        int dp[100005];
                        dp[0]=a[0];
                        int b=1;
                        for(i=1;i<N;i++)
                        {
                                int now=dp[i-1]+a[i];
                                if(a[i]>now)
                                {
                                        dp[i]=a[i];
                                        b=i+1;
                                }
                                else
                                {
                                        dp[i]=now;
                                }
                                if(dp[i]>ans)
                                {
                                        ans=dp[i];
                                        ans1=b;
                                        ans2=i+1;
                                }
                        }
                        printf("Case %d:\n%d %d %d\n\n",++c,ans,ans1,ans2);
                }
        }
        return 0;
}
