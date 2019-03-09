#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>

//判断有向图是否仅为1条连通直线:
//1.M=N-1  
//2.每次添加边是点的前驱改点不能已存在前驱，后驱同理 
//3.找到一个无前驱的点，该点一直往下遍历过得点数==N 
using namespace std;
int main()
{
	int T,c=0;
	cin>>T;
	int nxt[100005],pre[100005];
	queue<int> q;
	while(T--)
	{
		int N,M;
		scanf("%d%d",&N,&M);
		for(int i=0;i<=N;i++) nxt[i]=pre[i]=0;
		int u,v;
		bool flag=true;
		for(int i=0;i<M;i++)
		{
			scanf("%d%d",&u,&v);
			if(!nxt[u]&&!pre[v]) 
			{
				nxt[u]=v;pre[v]=u;
			}
			else flag=false;
		} 
		printf("Case #%d:\n",++c);
		if(!flag||M!=N-1) {printf("NO\n");continue;}
		int cnt=0,S=0;
		for(int i=1;i<=N;i++)
		{
			if(!pre[i])
			{
				S=i;
				break;
			}
		}	
		cnt=0;
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
