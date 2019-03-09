#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Coin
{
	int v,cnt;		
}c[25];
bool cmp( Coin a,Coin b)
{
	return a.v > b.v;
}
int main()
{
	int N,C;
	while(~scanf("%d%d",&N,&C))
	{
		for(int i = 0;i < N;i++) scanf("%d%d",&c[i].v,&c[i].cnt);
		sort(c,c+N,cmp);
		int ans = 0;
		int use[25];
		while(1)
		{
			int res = C; 
			memset(use,0,sizeof(use));
			for(int i = 0;i < N ;i++)
			{
				if(c[i].cnt)
				{
					int tcnt = min(c[i].cnt,res/c[i].v);
					res -= tcnt*c[i].v;
					use[i] = tcnt;
				}
			}
			for(int i = N-1;i >= 0;i--)
			{
				
				if(res <= 0) break;
				if(c[i].cnt > use[i])
				{
					use[i]++;
					res -= c[i].v;
				}
			}
			if(res > 0) break;
			int Min = 0x3f3f3f3f;
			for(int i = 0;i < N;i++) if(use[i]) Min = min(Min,c[i].cnt/use[i]);
			for(int i = 0;i < N;i++) if(use[i]) c[i].cnt -= Min*use[i];
			ans += Min;
		}
		printf("%d\n",ans);
	}
	return 0;
}
