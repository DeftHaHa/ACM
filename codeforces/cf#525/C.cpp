#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int a[100005],Max = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		Max = max(a[i],Max);
	}
	int mod = Max + n;
	int now = Max+n+n,temp = 0;
	cout<<n+1<<endl;
	for(int i = n-1;i >= 0;i--)
	{
		now--;// cout<<'#'<<i+1<<' '<<a[i]<<' '<<now<<' '<<temp<<endl;
		int x = (now - (a[i]+temp) + mod)%mod;
		printf("1 %d %d\n",i+1,x);
		temp = (temp+x)%mod;
	}
	printf("2 %d %d\n",n,mod);
	return 0;
}
