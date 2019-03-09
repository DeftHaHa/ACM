#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
const long long mod=1e10+7;
int main()
{
	long long fib[100005];
	fib[1]=1;
	fib[2]=2;
	for(int i=3;i<100001;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%mod;
	}

	string s;
	while(cin>>s)
	{
		long long x=0;
		for(int i=0;i<s.length();i++)
		{
			x=(x*10+(s[i]-'0'))%mod;
		}
		for(int i=0;i<100001;i++)
		{
			if(x==fib[i])
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
