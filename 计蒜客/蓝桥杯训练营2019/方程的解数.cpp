#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,M,k[25],p[25];
int ans = 0;
int Pow(int a,int b){
	int res = 1;
	for(int i = 0;i < b;i++) res*=a;
	return res;
}
void dfs(int cnt,int sum){
	if(cnt > n){
		if(sum == 0)ans++;
		return;
	}
	for(int i = 1;i <= M;i++){
		dfs(cnt+1,sum + k[cnt]*Pow(i,p[cnt]));
	}
}
int main()
{
	cin>>n>>M;
	for(int i = 1;i <= n;i++) scanf("%d%d",&k[i],&p[i]);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
