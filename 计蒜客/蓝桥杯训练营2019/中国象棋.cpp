#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
char maze[15][15];
bool vis[15][15];
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
bool flag = false;
void dfs(int x,int y){
	if(maze[x][y] == 'T'){
		flag = true;
		return;
	}
	vis[x][y] = true;
	for(int i = 0;i < 8;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx>0&&tx<=10&&ty>0&&ty<=9&&maze[tx][ty] != '#' && !vis[tx][ty]) dfs(tx,ty);
	}
}
int main()
{
	int sx,sy;
	memset(maze,'#',sizeof(maze));
	for(int i = 1;i <= 10;i++){
		for(int j = 1;j <= 9;j++){
			scanf("%c",&maze[i][j]);
			if(maze[i][j] == 'S') sx = i,sy = j;
		}
		getchar();
	}
	memset(vis,false,sizeof(vis));
	dfs(sx,sy);
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
