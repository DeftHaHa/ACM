#include<iostream>
#include<cstdio>
#include<cstdio>
#include<cstring>
using namespace std;
bool mp[505][505];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ex,ey,sx,sy;
bool flag;
bool vis[505][505];
void dfs(int x,int y)
{
	if(x==ex&&y==ey)
	{
		flag=true;
		return;
	}
	if(flag) return;
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(!vis[tx][ty]&&mp[tx][ty]) dfs(tx,ty);
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		int n,m;
		cin>>n>>m;
		char ch=getchar();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%c",&ch);
				if(ch=='.') mp[i][j]=1;
				else if(ch=='s')
				{
					sx=i;
					sy=j;
				}
				else if(ch=='t')
				{
					ex=i;
					ey=j;
				}
			}
			ch=getchar();
		}
		flag=false;
		mp[ex][ey]=1;
		dfs(sx,sy);
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
