#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	int n[505];
	while(scanf("%d",&N))
	{
		if(N==0) break;
		int sum=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&n[i]);
			sum+=n[i];
		}
		if(sum%N!=0) printf("Impossible\n");
		else
		{
			sum/=N;
			int ans=0;
			for(int i=0;i<N;i++) if(n[i]<sum) ans+=sum-n[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}