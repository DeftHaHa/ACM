#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[10][10];
int ans=0;
void dfs(int x,int y)
{
	if(x==0||y==6||x==6||y==0)
	{
		ans++;
		return;
	}
	vis[6-x][6-y]=true;
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(!vis[tx][ty]&&tx>=0&&tx<=6&&ty>=0&&ty<=6) dfs(tx,ty);
	}
	vis[x][y]=false;
	vis[6-x][6-y]=false;
}
int main()
{
	memset(vis,0,sizeof(vis));
	dfs(3,3);
	cout<<ans<<' '<<ans/4<<endl;
	return 0;
}
