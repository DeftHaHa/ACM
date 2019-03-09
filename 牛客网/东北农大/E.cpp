#include<iostream>
#include<cstdio>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int ans=0;
		while(n)
		{
			ans+=n/=5;
		}
		cout<<ans<<endl;
	}
	return 0;
}
