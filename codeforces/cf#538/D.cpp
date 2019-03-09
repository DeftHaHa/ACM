#include<iostream>
#include <math.h>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using  namespace std;
typedef long long ll;
const ll maxn=5e3+10;
int a[maxn],cnt;
int dp[maxn][maxn];
int main()
{
	int n,c;
    scanf("%d",&n);
    scanf("%d",&a[1]);
    cnt = 1;
    for(int i = 1;i < n;i++){
    	scanf("%d",&c);
    	if(c!=a[cnt]){
    		a[++cnt] = c;
		}
	}
	memset(dp,0,sizeof(dp));
	for(int len = 2;len <= cnt;len++){
		for(int l = 1;l + len - 1 <= cnt;l++){
			int r = l+len-1;
			if(a[l]==a[r]) dp[l][r] = dp[l+1][r-1]+1;
			else dp[l][r] = min(dp[l+1][r],dp[l][r-1])+1;
		}
	}
	printf("%d\n",dp[1][cnt]);
    return 0;
}
