#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[3005][3005];
int main()
{
	string s;
	cin>>s;
	string s1=s;    
	reverse(s.begin(),s.end());
	int len=s.size();
	for(int i=0;i<3005;i++) dp[i][0]=dp[0][i]=0;
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(s[i-1]==s1[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	cout<<len-dp[len][len]<<endl;
	return 0;
}
