#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	double ans=1;
	int n=20;
	while(n--)
	{
		ans=ans*2+0.5;
	}
	printf("%.1lf",ans);
	return 0;
}
