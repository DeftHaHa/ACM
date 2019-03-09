#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		n-=1;
		int ans=n;
		if(n==1) printf("0\n");
		else 
		{
			for(int i=2;i*i<=n&&n!=1;i++)
			{
				if(n%i==0)
				{
					ans-=ans/i;
					while(n%i==0)
					{
						n/=i;
					}
				}
			}
			if(n>1) ans-=ans/n;
			cout<<ans<<endl;
		}
	}
	
	
	return 0;
}
