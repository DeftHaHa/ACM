#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int mod = 1e5+7;
int main()
{
	int f[1005];
	f[1] = 1;
	f[2] = 2;
	int n;
	cin>>n;
	for(int i = 3;i <= n;i++) f[i] = (f[i-1]+f[i-2])%mod;
	cout<<f[n]<<endl;
	return 0;
}
