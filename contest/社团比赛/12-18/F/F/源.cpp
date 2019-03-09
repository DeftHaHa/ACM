#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int N;
	int p[105];
	cin>>N;
	for(int i=1;i<=N;i++) scanf("%d",&p[i]);
	for(int j=0;j<100;j++)
	{
		for(int i=1;i<=N;i++)
		{
			if(p[p[i]]==-1) p[i]=-1;
		}
	}
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		if(p[i]==-1) ans++;
	}
	printf("%d\n",ans*200+200);
	return 0;
}