#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1005],b[1005];
int dp[1005][1005];
int main()
{
	scanf("%s%s",a,b);
	int lena = strlen(a);
	int lenb = strlen(b);
	for(int i = 0;i <= lena;i++) dp[i][0] = i;
	for(int i = 0;i <= lenb;i++) dp[0][i] = i;
	for(int i = 1;i <= lena;i++){
		for(int j = 1;j <= lenb;j++){
			if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
		}
	}
	cout<<dp[lena][lenb]<<endl;
	return 0;
}
