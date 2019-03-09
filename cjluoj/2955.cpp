#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
        int T, M;
        int w[105],v[105];
        int i,j;
        int dp[1005];
        while(cin>>T>>M)
        {
                memset(dp,0,sizeof(dp));
                for(i=1;i<=M;i++)
                        cin>>v[i]>>w[i];
                for(i=1;i<=M;i++)
                        for(j=T;j>=v[i];j--)
                                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
                cout<<dp[T]<<endl;
        }
        return 0;
}
