#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100005;
long long a[maxn];
int main()
{
	int n;
	long long d;
	long long ans=0;
	while(~scanf("%d %d",&n,&d))
	{
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		int fail=2,j;
		for(int i=0;i<n-2;i++)
		{
			for(j=fail;j<n;j++)
			{
				if(a[j]>a[i]+d)
				{
					fail=j;
					break;
				}
			}
			long long x=j-i-2;
			ans+=(x*x+x)/2;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
