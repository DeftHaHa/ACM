#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int l[105];
	for(int i = 0;i < n;i ++){
		scanf("%d",&l[i]);
	}
	int ans = 0x3f3f3f3f;
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			ans =  min(ans,abs(l[i] - l[j]));
		}
	}
	printf("%d\n",ans);
	return 0;
}
