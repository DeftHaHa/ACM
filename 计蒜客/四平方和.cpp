#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int N;
int p[10005];
int maxn;
bool vis[5000005];
int a[4];
int main()
{
	cin>>N;
	maxn=(int)sqrt(N)+1;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<=maxn;i++)
	{
		p[i]=i*i;
		vis[p[i]]=true;
	}
	for(int a=0;a<=maxn;a++)
	{
		for(int b=0;b<=maxn;b++)
		{
			int sum=p[a]+p[b];
			if(sum<=N)
			for(int c=0;c<=maxn;c++)
			{   
				int SUM=sum+p[c];
				if(SUM<=N&&vis[N-SUM])
				{
					printf("%d %d %d %d\n",a,b,c,(int)sqrt(N-SUM));
					return 0;
				}
			}
		}
	}
	return 0;
}
