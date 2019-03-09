#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	int a[505],b[505];
	long long ans[1005];
	while(~scanf("%d%d",&n,&m))
	{
		memset(ans,0,sizeof(ans));
		for(int i=0;i<=n;i++) scanf("%d",&a[i]);
		for(int i=0;i<=m;i++) scanf("%d",&b[i]);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				ans[i+j]+=a[i]*b[j];  
			}
		}
		printf("%lld",ans[0]);
		for(int i=1;i<=n+m;i++)
		{
			printf(" %lld",ans[i]);
		}
		cout<<endl;
	}
	return 0;
}
