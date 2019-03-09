#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char maze[105][105];
int n,m;
int dxw[] = {0,0,2,-2};
int dyw[] = {2,-2,0,0};
int dxg[] = {0,0,1,-1};
int dyg[] = {1,-1,0,0};
void dfs1(int x,int y){
	maze[x][y] = 'w';
	for(int i = 0;i < 4;i++){
		int tx = dxw[i] + x;
		int ty = dyw[i] + y;
		if(tx>0&&tx<=n&&ty>0&&ty<=m&&maze[tx][ty]!='w'&&maze[tx][ty]!='#'){
			dfs1(tx,ty);
		}
	}
}
bool flag = false;
void dfs2(int x,int y){
	if(maze[x][y] == 'w'){
		flag = true;
		return;
	}
	maze[x][y] = 'g';
	for(int i = 0;i < 4;i++){
		int tx = dxg[i] + x;
		int ty = dyg[i] + y;
		if(maze[tx][ty]!='#'&&maze[tx][ty]!='g'){
			dfs2(tx,ty);
		}
	}
}
int main()
{
	cin>>n>>m;
	memset(maze,'#',sizeof(maze));
	getchar();
	int sx1,sx2,sy1,sy2;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%c",&maze[i][j]);
			if(maze[i][j] == 'w') sx1 = i,sy1 = j;
			else if(maze[i][j] == 'g') sx2 = i,sy2 = j;
		}
		getchar();
	}
	dfs1(sx1,sy1);
	dfs2(sx2,sy2);
	if(flag) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
