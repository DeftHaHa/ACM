#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int a[1005];
	int n;
	scanf("%d",&n);
	for(int i = 0 ;i < n;i++){
		scanf("%d",&a[i]);
	}
	int sum = 0,ans = 0xc0c0c0c0;
	for(int i = 0;i < n;i++){
		sum += a[i];
		ans = max(ans,sum);
		if(sum < 0) sum = 0;
	}
	printf("%d\n",ans);
	return 0;
}
