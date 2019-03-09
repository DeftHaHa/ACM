#include<iostream>
#include<cstdio>
#include<cstdio>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long n;
		cin>>n;
		int ans=0;
		while(n)
		{
			if(n%10==7) ans++;
			n/=10;
		}
		cout<<ans<<endl;
	}
	return 0;
}
