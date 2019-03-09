#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct MC
{
	int v,w;
	double p; 
}mc[10005];
bool cmp(MC a,MC b)
{
	return a.p > b.p;
}
int main()
{
	int N,D;
	while(~scanf("%d%d",&N,&D))
	{
		for(int i = 0;i < N;i++) scanf("%d",&mc[i].v);
		for(int i = 0;i < N;i++)
		{
			scanf("%d",&mc[i].w);
			mc[i].p = (double)mc[i].w/mc[i].v;
		}
		sort(mc,mc+N,cmp);
		double ans = 0;
		for(int i = 0;i < N;i++)
		{
			if(D <= mc[i].v)
			{
				ans += D * mc[i].p;
				break;
			}
			D -= mc[i].v;
			ans += mc[i].w;
		}
		printf("%.2lf\n",ans);
	}
	return  0;
}
