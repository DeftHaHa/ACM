#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int main()
{
	int n,m;
	long long a[100005];
	cin>>n>>m;
	long long cnt = 0;
	long long tot = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%I64d",&a[i]);
		tot += a[i];
	}
	sort(a,a+n);
	for(int i = 0;i < n;i++)
	{
		if(a[i]&&a[i]>cnt)
		{
			cnt++;
		}
	}
	cout<<tot-(n - cnt+ a[n-1])<<endl;
	return 0;
}
