#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[5];
	while(scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF)
	{
		sort(a,a+3);
		printf("%d->%d->%d\n",a[0],a[1],a[2]);
	}
	return 0;
}