#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int fa[100005];
bool vis[100005];
bool flag;
int get(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}
void init()
{
	for(int i=1;i<=100000;i++) fa[i]=i;
	memset(vis,false,sizeof(vis));
	flag=true;
}
void merge(int a,int b)
{
	a=get(a);
	b=get(b);
	if(a!=b) fa[a]=b;
	else flag=false;
}
int main()
{
	int u,v;
	
	while(~scanf("%d%d",&u,&v))
	{
		if(u==-1&&v==-1) break;
		init();
		while(1)
		{
			if(!u&&!v) break;
			vis[u]=vis[v]=true;
			merge(u,v);
			scanf("%d%d",&u,&v);
		}
		if(flag)
		{
			int cnt=0;
			for(int i=1;i<=100000;i++) if(vis[i]&&fa[i]==i) cnt++;
			if(cnt<=1) printf("Yes\n");
			else printf("No\n");
		}
		else printf("No\n");
	}
	return 0;
}
