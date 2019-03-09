#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
bool vis[5][15];
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
int ans=0;
void dfs(int x,int y,int cnt)
{
	if(cnt==2*n)
	{
		ans++;
		return;
	}
	vis[x][y]=true;
	for(int i=0;i<8;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(!vis[tx][ty]&&tx>0&&ty>0&&tx<=2&&ty<=n)
		{
			dfs(tx,ty,cnt+1);
		}
	}
	vis[x][y]=false;
}
int main()
{
	cin>>n;
	memset(vis,false,sizeof(vis));
	dfs(1,1,1);
	cout<<ans<<endl;
}
