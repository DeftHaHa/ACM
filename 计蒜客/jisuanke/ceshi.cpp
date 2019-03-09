#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	int T,c=0;
	cin>>T;
	int outd[100005],ind[100005];
	int nxt[100005];
	queue<int> q;
	while(T--)
	{
		int N,M;
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++) outd[i]=ind[i]=nxt[i]=0;
		int u,v;
		bool flag=true;
		for(int i=0;i<M;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(u!=v)
			{
				nxt[u]=v;
				outd[u]++;
				ind[v]++;
			}
			
		}
		printf("Case #%d:\n",++c);
		int cnts=0,cnte=0,S;
		for(int i=1;i<=N;i++)
		{
			if(outd[i]>1)
			{
				flag=false;
				break;
			}
			if(ind[i]>1)
			{
				flag=false;
				break;
			}
			if(!outd[i]) cnte++;
			if(!ind[i])
			{
				cnts++;
				S=i;
			}
		}
		if(!flag||cnte!=1||cnts!=1)
		{
			printf("NO\n");
			continue;
		}
		int cnt=0;
		for(int i=S;i;i=nxt[i]) cnt++;
		if(cnt!=N)
		{
			printf("NO\n");
			continue;
		}
		printf("%d",S); 
		S=nxt[S];
		for(int i=S;i;i=nxt[i]) printf(" %d",i);
		printf("\n");
	}
	return 0;
} 
