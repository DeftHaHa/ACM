#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int n;
	long long a; 
	while(T--)
	{
		scanf("%d%lld",&n,&a);
		if(n>2||n==0) printf("-1 -1\n");
		else if(n==1) printf("1 %lld\n",a+1);
		else
		{
			long long b,c;
			if(a&1)
			{
				b=(a*a-1)/2;
				c=b+1;
			}
			else
			{
				b=(a*a-4)/4;
				c=b+2;
			}
			printf("%lld %lld\n",b,c);
		}
		
	}
	return 0;
} 
