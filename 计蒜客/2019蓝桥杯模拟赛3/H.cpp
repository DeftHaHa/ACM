#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
int maze[505][505],Max[505][505];
int dx[] = {0,1};
int dy[] = {1,0};
void dfs(int x,int y,int sum){
	if(sum > Max[x][y]) Max[x][y] = sum;
	else return;
	for(int i = 0;i < 2;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx <= n && ty <= m){
			dfs(tx,ty,sum + maze[tx][ty]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	memset(Max,0xc0,sizeof(Max));
	dfs(1,1,maze[1][1]);
	printf("%d\n",Max[n][m]);
	return 0;
}
