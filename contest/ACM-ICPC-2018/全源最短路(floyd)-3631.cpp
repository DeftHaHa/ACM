#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=305;
int mp[maxn][maxn];
int N,M,Q;
bool mark[maxn];
int floyd(int k)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			mp[i][j]=min((mp[i][k]+mp[k][j]),mp[i][j]);
		}
	}
}
int main()
{
	int c=0;
	bool flag=false;
	while(~scanf("%d%d%d",&N,&M,&Q))
	{
		if(!N&&!M&&!Q) return 0;
		if(flag)
		{
			printf("\n");
			
		}
		flag=true;
		int u,v,w;
		memset(mp,0x3f,sizeof(mp));
		memset(mark,false,sizeof(mark));
		while(M--)
		{
			scanf("%d%d%d",&u,&v,&w);
			mp[u][v]=min(mp[u][v],w);  //¿Óµã 
		}
		for(int i=0;i<N;i++) mp[i][i]=0;
		printf("Case %d:\n",++c);
		while(Q--)
		{
			scanf("%d",&w);
			if(!w)
			{
				scanf("%d",&u);
				if(mark[u]) printf("ERROR! At point %d\n",u);
				else
				{
					mark[u]=true;
					floyd(u);
				}
			}
			else
			{
				scanf("%d%d",&u,&v);
				if(!mark[u]||!mark[v]) printf("ERROR! At path %d to %d\n",u,v);
				else if(mp[u][v]==0x3f3f3f3f) printf("No such path\n");
				else printf("%d\n",mp[u][v]);
			}
		}
		
	}
	return 0;
}
