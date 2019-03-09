#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int cnt[105];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int d;
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i < n;i++){
		scanf("%d",&d);
		cnt[d%k]++;
	}
	int ans = cnt[0]/2;
	for(int i = 1;i < k/2;i++){
		ans += min(cnt[i],cnt[k-i]);
	}
	if(k&1) ans += min(cnt[k/2],cnt[k-k/2]);
	else ans += cnt[k/2]/2;
	printf("%d\n",ans*2);
	return 0;
}
