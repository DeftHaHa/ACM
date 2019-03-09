#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int MD(int n)
{
	for(int i = 2;i <= sqrt(n);i++)
	{
		if(n%i==0) return i;
	}
	return 0;
}
int solve(int n)
{
	for(int i = 2;i <= sqrt(n);i+=2)
	{
		if(MD(n-i) == 0) return i;	
	}
	return 2;
}
int main()
{
	int T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		int md = MD(n);
		if(n <= 3 || md == 0) cout<<1<<endl;
		else if(k==1) cout<<n/md<<endl;
		else if(k>=2)
		{
			if(n&1)
			{
				if(k==2) cout<<solve(n)/2 + 1<<endl;
				else cout<<min(3,solve(n)/2+1)<<endl;
			}
			else
			{
				cout<<2<<endl;
			}
		}

	}
	return 0;
}
