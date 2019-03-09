#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int fa[10005];
struct edge
{
	int u,v,w;
}e[110005];
int get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
int n,m;
int ter[10005];
bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<m;i++) 
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		int u=e[i].u;
		int v=e[i].v;
		u=get(u);
		v=get(v);
		if(u!=v) fa[u]=v;
	}
	int sc=0;
	for(int i=1;i<=n;i++) if(fa[i]==i) sc++;
	int ans1;
	bool flag=false;
	if(sc==1)
	{
		ans1=0;
		flag=true;
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(e,e+m,cmp);
		for(int i=0;i<m;i++)
		{
			int u=e[i].u;
			int v=e[i].v;
			u=get(u);
			v=get(v);
			if(e[i].w<0)
			{
				ans1+=e[i].w;
				if(u!=v) fa[u]=v;
			}
			else if(u!=v)
			{
				ans1+=e[i].w;
				fa[u]=v;
			}
		}
	}
	int tot=m;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&ter[i]);
		if(ter[i]!=-1)
		{
			e[tot].u=0;       //引入0节点与码头相连
			e[tot].v=i;
			e[tot++].w=ter[i];
		}
		fa[i]=i;
	}
	fa[0]=0;
	sort(e,e+tot,cmp);
	int ans=0;
	for(int i=0;i<tot;i++)
	{
		int u=e[i].u;
		int v=e[i].v;
		u=get(u);
		v=get(v);
		if(e[i].w<0)
		{
			ans+=e[i].w;
			if(u!=v) fa[u]=v;
		}
		else if(u!=v)
		{
			ans+=e[i].w;
			fa[u]=v;
		}
	}
	if(flag) ans=min(ans,ans1);
	cout<<ans<<endl;
	return 0;
}
