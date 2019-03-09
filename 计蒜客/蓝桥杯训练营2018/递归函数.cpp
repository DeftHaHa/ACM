#include<iostream>
#include<cstdio>
using namespace std;
long long f(long long x){
	if(x<=0) return 0;
	if(x == 1) return 1;
	if(x&1) return 3*f((x+1)/2)-1;
	else return 3*f(x/2)-1;
}
int main()
{
	long long x;
	scanf("%lld",&x);
	printf("%lld\n",f(x));
	return 0;
}
