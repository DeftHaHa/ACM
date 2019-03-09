#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int ans=1<<n;
		printf("2^%d = %d\n",n,ans);
	}
	return 0;
}