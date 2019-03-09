#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int Max[1000005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int l,r;
	memset(Max,0,sizeof(Max));
	while(m--){
		scanf("%d%d",&l,&r);
		Max[l] = max(Max[l],r);
	}
	int ans = 0,maxr = 0;
	for(int i = 1;i <= n;i++){
		maxr = max(maxr,Max[i]);
		if(maxr<i) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
