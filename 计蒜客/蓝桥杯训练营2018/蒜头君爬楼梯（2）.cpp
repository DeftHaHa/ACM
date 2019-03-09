#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int mod = 1e5+7;
int main()
{
	int f[1005];
	memset(f,0,sizeof(f));
	f[0] = 1;
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= i;j += 2)
		{
			f[i] = (f[i]+f[i-j])%mod;
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
