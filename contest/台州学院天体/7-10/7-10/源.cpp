#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mp[1005][1005];
int n,m;
int fa[1000005];
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
void dfs(int x,int y,int fa)
{
	for(int i=x;i>=0;i--) //up
	{
		if(mp[i][y]&&fa[mp[i][y]]==mp[i][y])
		{
			merge(fa,mp[i][y]);
			dfs(i,y,mp[i][y]);
			break;
		}
	}
	for(int i=x;i<n;i++)//down
	{
		if(mp[i][y]&&fa[mp[i][y]]==mp[i][y])
		{
			merge(fa,mp[i][y]);
			dfs(i,y,mp[i][y]);
			break;
		}
	}
	for(int j=y;j>=0;j--)//left
	{
		if(mp[x][j]&&fa[mp[x][j]]==mp[x][j])
		{
			merge(fa,mp[x][j]);
			dfs(x,j,mp[x][j]);
			break;
		}
	}
	for(int j=y;j<m;j++)//right
	{
		if(mp[x][j]&&fa[mp[x][j]]==mp[x][j])
		{
			merge(fa,mp[x][j]);
			dfs(x,j,mp[x][j]);
			break;
		}
	}
}
int main()
{
	cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d",&mp[i][j]);
			if(mp[i][j]) mp[i][j]=++cnt;
		}
	for(int i=1;i<=cnt;i++) fa[i]=i;	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]&&fa[mp[i][j]]==mp[i][j])
			{
				dfs(i,j,mp[i][j]);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}