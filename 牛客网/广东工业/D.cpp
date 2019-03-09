#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1240];
int dp[1250][1250];
int main()
{
	
	while(~scanf("%s",s))
	{
		
		int l=strlen(s);
		for(int i=0;i<l;i++)
		{
			if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
		}
		char s2[1250];
		for(int i=0;i<l;i++) s2[i]=s[l-i-1];
		for(int i=0;i<1250;i++) dp[0][i]=dp[i][0]=0;
		for(int i=1;i<=l;i++)
		{
			for(int j=1;j<=l;j++)
			{
				if(s[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",l-dp[l][l]);
		
		memset(s,0,sizeof(s));
	}
	return 0;
}
