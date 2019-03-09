#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[65],b[65];
//f[n] = f[n-1] + 1 + f[n-1];  步数  == 2^n - 1
//sum[n] = sum[n-1] + n +  sum[n-1]; 花费 
int main()
{
	int n;
	scanf("%d",&n);
	a[1] = b[1] = 1;
	for(int i = 2;i <= n;i++) b[i] = 2*b[i-1] + i;
	printf("%lld %lld\n",(1LL<<n)-1,b[n]);
	return 0;
}
