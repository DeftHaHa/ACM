#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		int x=n/gcd(a,b);
		if(x&1) printf("huaye\n");
		else printf("suantou\n");
	}
	return 0;
}
