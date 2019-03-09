#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long jc[15];
	jc[1]=1;
	for(long i=2;i<=10;i++) jc[i]=jc[i-1]*i;
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		long long sum=0;
		for(int i=1;i<=N;i++) sum+=jc[i];
		printf("%lld\n",sum);
	}
	return 0;
}