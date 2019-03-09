#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct Product
{
	int v,d;
}p[10005];
bool cmp(Product a,Product b)
{
	return a.v>b.v;
}
poriority_queue<int,vector<>
int main()
{
	int N;
	while(~scanf("%d",&N))
	{
		int Maxd = 0xc0c0c0c0;
		for(int i = 0;i < N;i++)
		{
			scanf("%d",&p[i].v,&p[i].d);
			Maxd = max(Maxd,p[i].d);
		}
		
	}
	return 0;
}
