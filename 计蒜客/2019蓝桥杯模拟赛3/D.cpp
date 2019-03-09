#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int LEN = 18;
bool check_row(int n){
	return (n&(n>>1)) == 0;
}
bool check_up(int a,int b){
	return (a&b) == 0;
}
int cnt=0,num[100005];
ll dp[20][100005];
int main()
{
	for(int i = 0;i < (1<<LEN);i++){
		if(check_row(i)){
			num[++cnt] = i;
		}
	}
	cout<<cnt<<endl;
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= cnt;i++) dp[1][i] = 1;	
	
	for(int i = 2;i <= LEN;i++){
		for(int j = 1;j <= cnt;j++){
			for(int k = 1;k <= cnt;k++){
				if(check_up(num[k],num[j])){
					dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
				}
			}
		}
		cout<<"==="<<i<<endl;
	}
	ll ans = 0;
	for(int i = 1;i <= cnt;i++){
		ans = (ans + dp[LEN][i])%mod;
	}
	cout<<ans<<endl;
	//300222286
	
	return 0;
}
