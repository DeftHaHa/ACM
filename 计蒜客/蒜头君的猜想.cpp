#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool is_p[8000005];
int main()
{
	int n;
	cin>>n;
	memset(is_p,true,sizeof(is_p));
	is_p[0]=is_p[1]=false;
	for(long long i=2;i<=n;i++)
	{
		if(is_p[i])
		for(long long j=i*i;j<=n;j+=i)
			is_p[j]=false;
	}
	int ans=0;
	for(int i=2;i<=n/2;i++)
	{
		if(is_p[i]&&is_p[n-i])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
