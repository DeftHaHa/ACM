#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i = 1;i <= n;i++){
		printf("1");
		if(i<n) printf(" ");
	}
	printf("\n");
	return 0;
}
