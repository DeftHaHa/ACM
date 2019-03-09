#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int T,N;
	scanf("%d",&T);
	int t[1005];
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i < N;i++) scanf("%d",&t[i]);
		sort(t,t+N);
		int n = N-1,ans = 0;
		while(n >= 3)
		{
			ans+=min(t[0]+2*t[1]+t[n],2*t[0]+t[n]+t[n-1]);
			n-=2;
		}
		if(n==2) ans+=t[0]+t[1]+t[2];
	    if(n==1) ans+=t[1];
	    if(n==0) ans+=t[0];
	    printf("%d\n",ans);
	}
	return 0;
}
