#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int a[100005];
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		long long d=0,sum=0;
		for(int i=1;i<n-1;i++)
		{
			d+=a[i]-a[i-1];
			sum+=a[i];
		}
		sum+=a[0];
		long long temp=(n-1)*(d+a[n-1]+n-3)-sum;
		long long ans=temp/(n-1);
		if(temp%(n-1)) ans++;
		printf("%lld %lld\n",ans,d+a[n-1]+n-3);
	}
	return 0;
}
