#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[25][2];
int num[20];
ll dfs(int pos,bool sta,bool limit){
	if(pos == -1) return sta;
	if(!limit && dp[pos][sta]!=-1) return dp[pos][sta];
	int up = limit ? num[pos]:9;
	ll res = 0;
	for(int i = 0;i <= up;i++){
		res += dfs(pos-1,sta||i==6,limit&&i==up);
	}
	if(!limit) dp[pos][sta] = res;
	return res;
}
ll solve(ll n){
	int pos = 0;
	memset(dp,-1,sizeof(dp));
	while(n){
		num[pos++] = n%10;
		n/=10;
	}
	return dfs(pos-1,false,true);
}
int main()
{
	ll l,r;
	scanf("%lld%lld",&l,&r);
	cout<<solve(r)<<' '<<solve(l-1)<<endl;
	cout<<dp[0][0]<<' '<<dp[0][1]<<endl ;
	printf("%lld\n",solve(r)-solve(l-1));
	return 0;
}
