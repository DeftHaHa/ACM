#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int a[maxn],cnt[maxn*2];
int main()
{
	int n;
	int x=100000;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int mid=n/2-1;
		if(n&1) mid+=1;
		int tp=n;
		if(!(n&1))
		{
			if(a[mid+1]==a[mid+2]) tp=n-2;
			else tp=n-1;
		}
		for(int i=0;i<=200005;i++) cnt[i]=tp;
		for(int i=1;i<=mid;i++)
		{
			int t=x-i+a[i];
			cnt[t]--;
			if(x-i+a[n-i+1]==t) cnt[t]--;
		}
		int ans=0x3f3f3f3f;
		for(int i=1;i<=200005;i++) ans=min(ans,cnt[i]);
		printf("%d\n",ans);
	}
	return 0;
}
