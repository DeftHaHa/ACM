#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
long long d[55][30];
long long ans=0x3f3f3f3f;
bool vis[30],VIS[30];
void dfs(int id,int tot)
{
	vis[id]=true;
	if(tot==k)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			long long mind=0x3f3f3f3f;
			for(int j=1;j<=m;j++)
			{
				if(vis[j]) mind=min(d[i][j],mind);
			}
			sum+=mind;
		}
		if(sum<ans)
		{
			ans=sum;
			for(int i=1;i<=m;i++) VIS[i]=vis[i];
		}
		vis[id]=false;
		return;
	}
	for(int i=id+1;i<=m;i++)
	{
		dfs(i,tot+1);
	}
	vis[id]=false;
}
int main()
{
	int px[55],py[55],yx[30],yy[30];
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) scanf("%d%d",&px[i],&py[i]);
	for(int i=1;i<=m;i++) scanf("%d%d",&yx[i],&yy[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int dx=px[i]-yx[j],dy=py[i]-yy[j];
			d[i][j]=dx*dx+dy*dy;
		}
	}
	memset(vis,false,sizeof(vis));
	dfs(0,0);
	for(int i=1;i<=m;i++) if(VIS[i]) printf("%d ",i);
	cout<<endl;
	return 0;
}
