#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int pos = 1;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		while(a[i] - a[pos] > 5) pos++;
		ans = max(ans,i-pos+1);	
	}
	printf("%d\n",ans);
	return 0;
}
