#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char Map[15][15];
bool vis[15][15];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int tot;
void dfs(int x,int y){
	if(Map[x][y] == 'e'){
		tot++;
		return;
	}
	vis[x][y] = true;
	for(int i = 0;i < 4;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(Map[tx][ty] != '#'&& !vis[tx][ty]){
			dfs(tx,ty);
		}
	}
	vis[x][y] = false;
}
int main()
{
	int n,m;
	cin>>n>>m;
	memset(Map,'#',sizeof(Map));
	int sx,sy;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <=m;j++){
			cin>>Map[i][j];
			if(Map[i][j] =='s'){
				sx = i;
				sy = j;
			}
		}
	}
	memset(vis,false,sizeof(vis));
	tot = 0;
	dfs(sx,sy);
	cout<<tot<<endl;
	return 0;
}
