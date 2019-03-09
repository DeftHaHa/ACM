#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
int dp[1005][1005];
int main()
{
        string s1,s2;
        int T;
        cin>>T;
        while(T--)
        {
                cin>>s1>>s2;
                int l1=s1.length(),l2=s2.length();
                for(int i=0;i<=l1;i++)
                {
                        dp[i][0]=i;
                }
                for(int i=0;i<=l2;i++)
                {
                        dp[0][i]=i;
                }
                for(int i=1;i<=l1;i++)
                {
                        for(int j=1;j<=l2;j++)
                        {
                                int cost;
                                if(s1[i-1] == s2[j-1])  cost = 0;
                                else  cost = 1;
                                dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+cost));
                        }
                }
                cout<<dp[l1][l2]<<endl;
        }
        return 0;
}
