#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int mp[10][10]={{3,4,5,7,6},{6,2,8,4,12},{7,12,4,8,3},{1,9,5,10,7},{8,5,6,5,2}};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans=0;
bool vis[10][10];
void dfs(int x,int y,int cnt,int sum,int pro)
{
	sum+=mp[x][y];
	if(sum>24) return;
	pro*=mp[x][y];
	if(cnt==5)
	{
		ans=max(ans,pro);
		return;
	}
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx>=0&&ty>=0&&tx<5&&ty<5&&!vis[tx][ty]) dfs(tx,ty,cnt+1,sum,pro);
	}
	vis[x][y]=false;
}
int main()
{
	memset(vis,false,sizeof(vis));
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			dfs(i,j,1,0,1);
		}
	}
	cout<<ans<<endl;
	return 0;
}

