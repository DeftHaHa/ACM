#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n;
	while(cin>>n)
	{
		long long ans=n/2+n/5+n/11+n/13-(n/10+n/22+n/26+n/55+n/65+n/143)+(n/110+n/130+n/715+n/286)-n/(110*13);
		cout<<n-ans<<endl;
	}
	return 0;
}
