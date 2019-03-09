#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[130];
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	bool vis[10005];
	memset(vis,false,sizeof(vis));
	int ans1 = a[n-1],ans2 = -1;
	vis[ans1] = true;
	for(int i = n-2;i >= 0;i--){
		if(ans1%a[i] || vis[a[i]]){
			vis[i] = true;
			ans2 = a[i];
			break;
		}
		else vis[a[i]] = true;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
