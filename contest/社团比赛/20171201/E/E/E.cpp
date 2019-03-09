#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int N,M;
	int x,y;
	int tot[105];
	int rank[105];
	while(scanf("%d",&N)!=EOF)
	{
		if(!N) break;
		memset(tot,0,sizeof(tot));
		memset(rank,0,sizeof(rank));
		int grade;
		while(N--)
		{
			scanf("%d",&grade);
			tot[grade]++;
		}
		int maxgrade;
		for(int i=100;i>=0;i--) if(tot[i]) {maxgrade=i;break;}
		rank[maxgrade]=1;
		for(int i=maxgrade+1;i>=0;i--)
		{
			rank[i]=rank[i+1]+tot[i+1];
		}
		scanf("%d",&M);
		while(M--)
		{
			scanf("%d%d",&x,&y);
			bool flag=false;
			for(int i=y;i>=x;i--)
			{
				if(tot[i])
				{
					flag=true; printf(" %d==",i);
					printf("%d ",rank[i]);
					break;
				}
			}
			for(int i=x;i<=y;i++)
			{
				if(tot[i])
				{
					flag=true; printf(" %d==",i);
					printf("%d\n",rank[i]);
					break;
				}
			}
			if(!flag) printf("0 0\n");
		}
	}
	return 0;
}