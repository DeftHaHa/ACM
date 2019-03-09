#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,ans,mc = 0;
int prime[25];
bool is_prime(int n){
	int r = sqrt(n);
	for(int i = 2;i <= r;i++){
		if(n%i==0) return false;
	}
	return true;
}
void dfs(int d,int m,ll cnt,ll num){
//	cout<<num<<' '<<cnt<<endl;
	if(cnt > mc){
		mc = cnt;
		ans = num;
	}else if(cnt == mc && num < ans) ans = num;
	if(d==15) return;
	for(int i = 1;i <= m ;i++){//到m要求最小，后面大的因子数量尽可能少 
		num = num * prime[d];
		if(num > n) break;
		dfs(d+1,i,cnt*(i+1),num);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	int cnt = 0;
	for(int i = 2;;i++){
		if(is_prime(i)) prime[cnt++] = i;
		if(cnt==20) break;
	}
	while(T--){
		scanf("%lld",&n);
		ans = mc = 0;
		dfs(0,60,1,1);
		printf("%lld\n",ans);
	}
	
	return 0;
}
