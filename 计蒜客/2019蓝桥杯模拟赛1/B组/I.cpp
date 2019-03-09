#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
int H,W;
bool vis[505][505],col[505][505];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void dfs(int x,int y){
	vis[x][y] = true;
	for(int i = 0;i < 4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx > 0 && ty >0 && tx <= H&&ty<=W&&!vis[tx][ty]&&col[tx][ty]!=0){
			dfs(tx,ty);
		}
	}
}
int main()
{
	scanf("%d",&N);
	char ch;
	while(N--){
		scanf("%d%d",&H,&W);
		getchar();
		for(int i = 1;i <= H;i++){
			for(int j = 1;j <= W;j++){
				scanf("%d",&col[i][j]);
			}
		}
		memset(vis,false,sizeof(vis));
		int sx,sy;
		for(int i = 1;i <= H;i++){
			if(col[i][1]){
				sx = i,sy = 1;
				if(!vis[sx][sy]) dfs(sx,sy);
			}
			if(col[i][W]){
				sx = i,sy = W;
				if(!vis[sx][sy]) dfs(sx,sy);
			}
		}
		for(int j = 1;j <= W;j++){
			if(col[1][j]){
				sx = 1,sy = j;
				if(!vis[sx][sy]) dfs(sx,sy);
			}
			if(col[H][j]) {
				sx = H,sy = j;
				if(!vis[sx][sy]) dfs(sx,sy);
			}
		}
		for(int i = 1;i <= H;i++){
			for(int j = 1;j <= W;j++){
				if(!vis[i][j]) printf("%d",col[i][j]);
				else printf("0");
				if(j!=W) printf(" ");
			}
			puts("");
		}
	}
	return 0;
}
