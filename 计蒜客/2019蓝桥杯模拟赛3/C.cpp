#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans = 0;
bool vis[4][5];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs(int x,int y,int cnt)
{
	if(x==3&&y==1&&cnt==15){
		ans++;cout<<"#"<<endl;
		return;
	}
	vis[x][y] = true;
	for(int i = 0;i < 4;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(tx>0&&ty>0&&tx<4&&ty<6&&!vis[tx][ty]){
			dfs(tx,ty,cnt+1);
		}
	}
	vis[x][y] = false;
}
int main()
{
	memset(vis,false,sizeof(vis));
	dfs(1,1,1);
	cout<<ans<<endl;
	return 0;
}
