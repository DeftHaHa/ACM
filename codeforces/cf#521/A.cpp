#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int T;
	long long a,b,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&k);
		if(k&1) printf("%I64d\n",(a-b)*(k/2)+a);
		else printf("%I64d\n",(a-b)*(k/2));
	}
	return 0;
}
