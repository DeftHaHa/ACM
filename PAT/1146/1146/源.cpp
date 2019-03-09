#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct edge
{
	int v,next;
}e[20005];
int p[20005],eid=0;
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int main()
{

	int ind[2005];
	int N,M;
	int u,v;
	cin>>N>>M;
	memset(ind,0,sizeof(ind));
	memset(p,-1,sizeof(p));
	while(M--)
	{
		scanf("%d%d",&u,&v);
		ind[v]++;
		addedge(u,v);
	}
	int K;
	cin>>K;
	int tin[2005];
	int node[2005];
	int ans[205],len=0;
	for(int k=0;k<K;k++)
	{
		for(int i=0;i<N;i++) scanf("%d",&node[i]);
		for(int i=1;i<=N;i++) tin[i]=ind[i];
		for(int i=0;i<N;i++)
		{
			if(tin[node[i]]!=0)
			{
				ans[len++]=k;
				break;
			}
			for(int j=p[node[i]];j!=-1;j=e[j].next)
			{
				tin[e[j].v]--;
			}
		}
	}
	if(len) cout<<ans[0];
	for(int i=1;i<len;i++) printf(" %d",ans[i]);
	cout<<endl;
	system("pause");
	return 0;
}