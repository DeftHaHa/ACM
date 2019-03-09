#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
long long a[1000005],b[1000005];
bool cmp(const long long &a,const long long &b)
{
	return a>b;
}
int main()
{
	int n;
	long long m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		for(int i=0;i<n;i++) scanf("%lld",&b[i]);
		sort(a,a+n);
		sort(b,b+n,cmp);
		long long ans=0;
		int step=0;
		int i;
		bool flag=true;
		for(i=0;i<n;i++)
		{
			long long d=b[i]-a[i];
			if(d>=0)
			{
				ans+=d;
			}
			else
			{
				flag=false;
				break;
			}
		}
		if(i>=n) ans+=m*(i/3);
		else
		{
			ans+=m*(i/3);
			int step=i%3;   //cout<<i<<' '<<step<<endl;
			long long sum=0;
			i--;
			while(i<n)
			{
				i++;
				step++;
				sum+=b[i]-a[i];
				if(step==3)
				{
					step=0;
					sum+=m;
					if(sum>0) ans+=sum;
					else break;
					sum=0;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
