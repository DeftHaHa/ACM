#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
char maze[105][105];
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
int n,m;
bool vis[105][105];
void dfs(int x,int y,int step){
	if(step > 2) return;
	vis[x][y] = true;
	for(int i = 0;i < 8;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx>0&&tx<=n&&ty>0&&ty<=m&&!vis[tx][ty]){
			maze[tx][ty] = '#';
			dfs(tx,ty,step+1);
		}
	}
}
int main()
{
	int sx,sy;
	scanf("%d%d%d%d",&n,&m,&sx,&sy);
	memset(maze,'.',sizeof(maze));
	maze[sx][sy] = '#';
	dfs(sx,sy,0);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			printf("%c",maze[i][j]);
		}
		printf("\n");
	}
	return 0;
}

