#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
bool mp[105][105];
bool vis[105][105];
int cnt=0;
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
struct node
{
	int x,y,step;
};
int X,Y,sx,sy;
queue<node> q;
int bfs(int sx,int sy)
{
	node now;
	now.x=sx;
	now.y=sy;
	now.step=0;
	int tot=1;
	q.push(now);
	memset(vis,0,sizeof(vis));
	vis[sx][sy]=true;
	while(!q.empty())
	{

		now=q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			node Next;
			Next.x=now.x+dx[i];
			Next.y=now.y+dy[i];
			if(!vis[Next.x][Next.y]&&mp[Next.x][Next.y])
			{
				vis[Next.x][Next.y]=true;
				Next.step=now.step+1;
				tot++;
				if(tot==cnt) return Next.step;
				q.push(Next);
			}
		}
	}	
}
int main()
{
	memset(mp,0,sizeof(mp));
	scanf("%d%d%d%d",&X,&Y,&sx,&sy);
	char ch=getchar();
	for(int i=Y;i>0;i--)
	{
		for(int j=1;j<=X;j++)
		{
			scanf("%c",&ch);
			if(ch=='.')
			{
				mp[i][j]=1;
				cnt++;
			}
		}
		ch=getchar();
	}         
	
	printf("%d\n",bfs(sy,sx));
	return 0;
}
