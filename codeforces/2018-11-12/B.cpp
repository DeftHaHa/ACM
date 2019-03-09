#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(int n)
{
	for(int j = 2;j <= sqrt(n);j++)
	{
		if(n%j == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	long long n;
	scanf("%I64d",&n);
	if(n&1)
	{
		bool flag = false;
		for(int i = 2;i <= sqrt(n);i++)
		{
			if(n % i == 0 && is_prime(i))
			{
				n -= i;
				flag = true;
				break;
			}
		}
		printf("%I64d\n",flag ? 1+n/2 : 1);
	}
	else
	{
		printf("%I64d\n",n/2);
	}
	return 0;
}
