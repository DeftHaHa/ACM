#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N;
int ind[10][10];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool vis[10][10];
int ans,tot;
bool inMap(int x,int y){ return (x>0&&y>0&&x<=N&&y<=N);}
void dfs(int x,int y,int cnt){
	if(x == N && y==1){
		if(cnt == N*N) ans++;
		return;
	}
	int dir = -1;
	vis[x][y] = true;
	for(int i = 0;i < 4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(inMap(tx,ty) && !vis[tx][ty]){
			ind[tx][ty]--;
			if(ind[tx][ty] == 1) dir = i;
		}
	}
	for(int i = 0;i < 4;i++){
		if(dir != -1 && i != dir) continue;
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(inMap(tx,ty) && !vis[tx][ty]){
			dfs(tx,ty,cnt+1);
		}
	}
	for(int i = 0;i < 4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(inMap(tx,ty) && !vis[tx][ty]){
			ind[tx][ty]++;
		}
	}
	vis[x][y] = false;
}
int main()
{
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++){
			if(i==1||i==N||j==1||j==N) ind[i][j] = 3;
			else ind[i][j] = 4;
		}
	}
	ind[1][1] = ind[1][N] = ind[N][1] = ind[N][N] = 2;
	ind[N][1] ++;
	ans = 0;
	tot = N*N;
	memset(vis,false,sizeof(vis));
	dfs(1,1,1);
	printf("%d\n",ans);
	return 0;
}
