#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char Map[105][105];
bool vis[105][105];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int tot;
void dfs(int x,int y){
	vis[x][y] = true;
	tot++;
	for(int i = 0;i < 4;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(Map[tx][ty] == '#'&& !vis[tx][ty]){
			dfs(tx,ty);
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	memset(Map,'.',sizeof(Map));
	int sx,sy;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <=m;j++){
			cin>>Map[i][j];
		}
	}
	memset(vis,false,sizeof(vis));
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <=m;j++){
			if(Map[i][j]=='#'  && !vis[i][j]){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
