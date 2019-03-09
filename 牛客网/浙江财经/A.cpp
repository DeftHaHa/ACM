#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int T,c=0;
	cin>>T;
	int a[1005];
	while(T--)
	{
		int N,K;
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++) scanf("%d",&a[i]);
		sort(a,a+N);
		int M,m;
		int ans=0;
		int i,j;
		for(i=0,j=K-1;j<N;i++,j++)
		{
			M=m=a[i];
			for(int x=i+1;x<=j;x++)
			{
				M=max(a[x],M);
				m=min(a[x],m);
			} 
			ans+=M-m;
		}
	
		
		printf("Case #%d: %d\n",++c,ans);
	}
	return 0;
}
