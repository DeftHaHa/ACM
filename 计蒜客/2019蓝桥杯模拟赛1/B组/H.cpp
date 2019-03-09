#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[500005];
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	if(n==1){
		puts("1");
		return 0;
	}
	int ans = n,pos = n/2;
	for(int i = 0;i <n/2 ;i++){
		while(pos < n && a[pos] < 2*a[i]) pos++;
		if(pos == n) break;
		ans--;
		pos++;
	}
	cout<<ans<<endl;
	return 0;
}
