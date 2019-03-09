#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool maze[105][105];
int m,n;
int x,y,k;
char s;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y,int dir,int step)
{
	if(step==k)
	{
		printf("%d %d\n",x,y);
		return;
	}
	if(maze[x][y])
	{
		int tx=x+dx[(dir+1)%4];
		int ty=y+dy[(dir+1)%4];
		maze[x][y]=!maze[x][y];
		dfs(tx,ty,(dir+1)%4,step+1);
	}
	else
	{
		int tx=x+dx[(dir+3)%4];
		int ty=y+dy[(dir+3)%4];
		maze[x][y]=!maze[x][y];
		dfs(tx,ty,(dir+3)%4,step+1);
	}
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++) scanf("%d",&maze[i][j]);
	scanf("%d %d %c %d",&x,&y,&s,&k);
	int dir;
	if(s=='U') dir=0; 
	else if(s=='D') dir=2;
	else if(s=='L')	dir=3;
	else if(s=='R') dir=1;
	dfs(x,y,dir,0);
	return 0;
}
