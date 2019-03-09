#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int num[105],a;
	int n,k;
	scanf("%d%d",&n,&k);
	memset(num,0,sizeof(num));
	int Max = 0,Type = 0;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a);
		if(!num[a]) Type++;
		num[a]++;
		Max = max(Max,num[a]);
	}
	int dish = Max%k == 0? Max/k : Max/k+1;
	printf("%d\n",Type*dish*k - n);
	return 0;
}
