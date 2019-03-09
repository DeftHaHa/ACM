#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n;
	long long s;
	cin>>n>>s;
	long long v[1005];
	long long Min = 1e10;
	for(int i = 0;i < n;i++)
	{
		scanf("%I64d",&v[i]);
		Min = min(v[i],Min);	
	}
	long long sum = 0;
	for(int i = 0;i < n;i++)
	{
		sum += v[i] - Min;
	}
	if(sum >= s) cout<<Min<<endl;
	else
	{
		long long ans = Min - (s-sum)/n;
		if((s-sum)%n) ans--;
		if(ans>=0) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	
	return 0;
}
