#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int a[100005];
bool vis[200005];
int main()
{
	int n;
	memset(vis,false,sizeof(vis));
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]),vis[a[i]] = true;
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			int sum = a[i]+a[j],cnt = 0;
			for(int k = 1;k <= n;k++){
				if(a[k] >= (sum+1)/2) break;
				if(vis[sum-a[k]]) cnt++;
			}
			ans = max(ans,cnt);
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
