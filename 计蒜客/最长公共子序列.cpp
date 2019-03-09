#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1005][1005];
int main()
{
	char s1[1005],s2[1005];
	scanf("%s%s",s1,s2);
	
	for(int i=0;i<1005;i++) dp[0][i]=dp[i][0]=0;
	int l1=strlen(s1),l2=strlen(s2);
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[l1][l2]<<endl;
	return 0;
}
