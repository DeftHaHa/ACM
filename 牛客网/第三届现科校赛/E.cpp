#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool vis[105][105];
char Map[105][105];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs(int x,int y)
{
	vis[x][y] = true;
	for(int i = 0;i < 4;i++)
	{
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(!vis[tx][ty]&&Map[tx][ty]=='_')
		{
			dfs(tx,ty);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		memset(Map,'#',sizeof(Map));
		for(int i = 1;i <= 10;i++)
		{
			for(int j = 1;j <= 10;j++)
				scanf("%c",&Map[i][j]);
			getchar();
		}
		memset(vis,false,sizeof(vis));
		for(int i = 1;i <=10 ;i++)
		{
			if(!vis[1][i]&&Map[1][i]=='_') dfs(1,i);
			if(!vis[10][i]&&Map[10][i]=='_') dfs(10,i);
		}
		for(int i = 1;i <=10 ;i++)
		{
			if(!vis[i][1]&&Map[i][1]=='_') dfs(i,1);
			if(!vis[i][10]&&Map[i][10]=='_') dfs(i,10);
		}
		int cc = 0;
		for(int i = 2;i <= 9;i++)
		{
			for(int j = 2;j <= 9;j++)
			{
				if(!vis[i][j]&&Map[i][j]=='_')
				{
					dfs(i,j);
					cc++;
				}
			}
		}
		if(cc==0) cout<<1<<endl;
		else if(cc==1) cout<<0<<endl;
		else cout<<8<<endl;
	}
	return 0;
}
