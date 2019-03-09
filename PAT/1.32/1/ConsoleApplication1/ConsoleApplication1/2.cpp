#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool prim[100005];
int main()
{
	memset(prim,true,sizeof(prim));
	for(int i=2;i<=sqrt(100000);i++)
	{
		if(prim[i])
		for(int j=i*i;j<=100000;j+=i)
			prim[j]=false;
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
		n-=2;
		for(int i=1;i<=n;i++)
		{
			if(prim[i]&&prim[i+2])
			{
				ans++;
				i+=3;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}