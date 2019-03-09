#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int n,m,q,k[405],z[405][405];
bool vis[405];
int ans = 0;
void dfs(int deep,int pos,int cnt){
	if(cnt == 0 || cnt == n) ans++;
	if(deep > 18) return;
	for(int i = pos+1;i <= m;i++){
		int t = cnt;
		for(int j = 1;j <= k[i];j++){
			if(vis[z[i][j]]) t--;
			else t++;
			vis[z[i][j]] = !vis[z[i][j]];
		}
		dfs(deep+1,i,t);
		for(int j = 1;j <= k[i];j++) vis[z[i][j]] = !vis[z[i][j]];
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++) scanf("%d",&z[i][j]);
	}
	while(q--){
		int t = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d",&vis[i]);
			if(vis[i]) t++;
		}
		ans = 0;
		dfs(1,0,t);
		printf("%d\n",ans);
	}
	return 0;
}
