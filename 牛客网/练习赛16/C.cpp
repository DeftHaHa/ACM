#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int fa[105];
int get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int a,int b)
{
	a=get(a);
	b=get(b);
	if(a!=b) fa[b]=a;
}
int main()
{
	int x[105],y[105];
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[i]==x[j]||y[i]==y[j]) merge(i,j);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(fa[i]==i) cnt++;
		}
		printf("%d\n",cnt-1);
	}
	
	return 0;
}
