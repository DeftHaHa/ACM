#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int mat[15][15];
int mp[15][15];
/*
struct node
{
	int x,y;
	int step; 
};
queue<node> q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int bfs(int sx,int sy,int ex,int ey)
{
	while(!q.empty()) q.pop();
	node S;
	S.x=sx;
	S.y=sy;
	S.step=0;
	q.push(S);
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		node Next;
		for(int i=0;i<4;i++)
		{
			Next.x=now.x+dx[i];
			Next.y=now.y+dy[i];
			if(Next.x==ex&&Next.y==ey)
			{
				return now.step+1;
			}
			if(mat[Next.x][Next.y])
			{
				Next.step=now.step+1;
				q.push(Next);
			}
		}
	}
}*/
bool vis[15];
int ans=0x3f3f3f3f;
vector<int> path;
void dfs(int now,int cnt,int sum)
{
	if(cnt==10)
	{
		if(sum+mp[now][1]<ans)
		{
			ans=sum+mp[now][1];
			for(int i=0;i<path.size();i++) printf("-->%d",path[i]);
			cout<<"="<<ans<<endl;
		}
		return;
	}
	else if(sum>ans||cnt>10) return;
	for(int i=2;i<=11;i++)
	{
		if(i!=now&&!vis[i])s
		{
			vis[i]=true; path.push_back(i);
			dfs(i,cnt+1,sum+mp[now][i]);
			vis[i]=false;  path.pop_back();
		}
	}
}
int main()
{
	int n;
	freopen("DATA.txt","r",stdin);
	memset(mat,0,sizeof(mat));
	memset(mp,0,sizeof(mp));
	int id=1;
	int x[15],y[15];
	x[1]=y[1]=1;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j]==2)
			{
				mat[i][j]=++id;
				x[id]=i;
				y[id]=j;
			}
		}
	}
/*
	for(int i=1;i<=11;i++)
	{
		for(int j=i+1;j<=11;j++)
		{
			mp[j][i]=mp[i][j]=bfs(x[i],y[i],x[j],y[j]);
		}
	}*/	
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=11;j++) scanf("%d",&mp[i][j]);
		
	}
	memset(vis,false,sizeof(vis));
	dfs(1,0,0);
	path.push_back(1);
	cout<<ans<<endl;
	return 0;
}
