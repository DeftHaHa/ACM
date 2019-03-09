#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Mp[1005][1005];
int fa[1000005];
bool vis[1005][1005];
int n,m;
int get(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}
void merge(int a,int b)
{
	a=get(a);
	b=get(b);
	if(a!=b) fa[a]=b;
}
void dfs(int x,int y,int father)
{  //cout<<"-->>"<<x<<' '<<y<<endl;
	vis[x][y]=true;
	for(int i=x-1;i>=0;i--) //up
	{
		if(Mp[i][y]&& !vis[i][y])
		{
			merge(father,Mp[i][y]);
			dfs(i,y,Mp[i][y]);
			break;
		}
	}
	for(int i=x+1;i<n;i++)//down
	{
		if(Mp[i][y]&& !vis[i][y])
		{
			merge(father,Mp[i][y]);
			dfs(i,y,Mp[i][y]);
			break;
		}
	}
	for(int j=y-1;j>=0;j--)//left
	{
		if(Mp[x][j]&&!vis[x][j])
		{
			merge(father,Mp[x][j]);
			dfs(x,j,Mp[x][j]);
			break;
		}
	}
	for(int j=y+1;j<m;j++)//right
	{
		if(Mp[x][j]&&!vis[x][j])
		{
			merge(father,Mp[x][j]);
			dfs(x,j,Mp[x][j]);
			break;
		}
	}
}  
int main()
{
	cin>>n>>m;
	int cnt=0;
	char x;
	char ch=getchar();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%c",&x);
			if(x=='1') Mp[i][j]=++cnt;
			else Mp[i][j]=0;
		}
		ch=getchar();
	}
	for(int i=1;i<=cnt;i++) fa[i]=i;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(Mp[i][j]&& !vis[i][j])
			{
				dfs(i,j,Mp[i][j]);
			}
		}
	}
	int tot=0;
	for(int i=1;i<=cnt;i++) if(fa[i]==i) tot++;
	cout<<tot<<endl;
	return 0;
}
