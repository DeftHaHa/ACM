#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
int H,W;
bool vis[505][505],yes[505][505];
bool col[505][505];
bool cir = false;
int x1,Y1,x2,y2;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void dfs(int x,int y,int deep){
	vis[x][y] = true;
	for(int i = 0;i < 4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx == x1&&ty == Y1&&deep>2)
			if((x==x1+1&&y==Y1)||(x==x1&&y==Y1+1)) cir = true;
		if(tx > 0 && ty >0 && tx <= H&&ty<=W&&!vis[tx][ty]&&col[tx][ty]==0){
			if(tx>=x2){
				x2 = tx;
				y2 = max(y2,ty);
			}
			dfs(tx,ty,deep+1);
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
		memset(yes,false,sizeof(yes));
		for(int i = 1;i <= H;i++){
			for(int j = 1;j <= W;j++){
				if(col[i][j]==0&&!vis[i][j]){
					cir = false;
					x1 = i,Y1=j;
					x2 = y2 = 0;
					dfs(i,j,1);
					//cout<<cir<<"===="<<endl;printf("%d %d  %d %d\n",x1,Y1,x2,y2);
					if(cir)
					for(int xx = x1;xx <= x2;xx++){
						for(int yy = Y1;yy <= y2;yy++){
							if(!vis[xx][yy]){
								vis[xx][yy] = true;
								yes[xx][yy] = true;
							}
						}
					}
				}
			}
		}
		for(int i = 1;i <= H;i++){
			for(int j = 1;j <= W;j++){
				if(yes[i][j]) printf("%d",col[i][j]);
				else printf("0");
				if(j!=W) printf(" ");
			}
			puts("");
		}
	}
	return 0;
}
