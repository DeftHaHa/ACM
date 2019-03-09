#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	long long f[55];
	f[1]=3;
	f[2]=f[3]=6;
	int n;
	cin>>n;
	if(n<=3) cout<<f[n]<<endl;
	else
	{
		for(int i=4;i<=n;i++) f[i]=f[i-1]+f[i-2]*2;
		cout<<f[n]<<endl;
	}
	
	return 0;
}
