#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int a[100005];
int main()
{
	int N;
	scanf("%d",&N);
	int sum = 0;
	for(int i = 1;i <= N;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sort(a+1,a+N+1);
	int bsum = 0;
	for(int i = 1;i <= N/2;i++) bsum+= a[i];
	printf("%d %d\n",N%2,sum-2*bsum);
	
	return 0;
}
