#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int father[10005];
struct edge
{
	int u,v,d;
}e[100005];
bool cmp(const edge &a,const edge &b)
{
	return a.d>b.d;
}
int get(int x)
{
	if(x==father[x]) return x;
	return father[x]=get(father[x]);
}
void merge(int a,int b)
{
	father[a]=b; 
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
	sort(e,e+m,cmp);
	int bef=0,a,b;
	int ans=0;
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=0;i<m;i++)
	{
		a=get(e[i].u);
		b=get(e[i].v);
		if(a!=b)
		{
			merge(a,b);
			if(e[i].d!=bef)
			{
				ans++;
				bef=e[i].d;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
