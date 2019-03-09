#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n=999999943999999559;
	long long f=2,ans;
	while(n&&f<=n)
	{
		if(n%f==0)
		{
			ans=f;   
			n/=f;
			while(n%f==0)
			{
				n/=f;
			}
		}
		f++;
	}
	cout<<ans<<endl;
	return 0;
} 
