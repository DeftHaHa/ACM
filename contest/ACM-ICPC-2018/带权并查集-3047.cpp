#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=50005;
int fa[maxn],dis[maxn];
int N,M;
int A,B,X;
int ans;
int get(int x)
{
	if(fa[x]==x) return x;
	int y=fa[x];
	fa[x]=get(y);
	dis[x]+=dis[y];
	return fa[x];
}
void merge(int x,int y,int d)
{
	int fx=get(x);
	int fy=get(y);
	if(fx!=fy)
	{
		fa[fy]=fx;
		dis[fy]=dis[x]+d-dis[y];
	}
	else
	{
		if(dis[y]-dis[x]!=d) ans++;
	}
}
int main()
{
	while(cin>>N>>M)
	{
		for(int i=1;i<+N;i++)
		{
			fa[i]=i;
			dis[i]=0;
		}
		ans=0;
		while(M--)
		{
			scanf("%d%d%d",&A,&B,&X);
			merge(A,B,X);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
