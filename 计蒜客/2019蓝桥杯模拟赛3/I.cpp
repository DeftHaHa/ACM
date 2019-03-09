#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	int n,a[1005];
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l = 1,r = n,last = n,ans = 0;
	vector<int> path[20005];
	int cnt = 0;
	while(last > 0){
		if(last == 1) path[++cnt].push_back(1),path[cnt].push_back(a[l]),ans += a[l],last = 0;
		else if(last == 2) path[++cnt].push_back(2),path[cnt].push_back(a[l]),path[cnt].push_back(a[l+1]),ans += a[l+1],last = 0;
		else if(last == 3){
			path[++cnt].push_back(2),path[cnt].push_back(a[l]),path[cnt].push_back(a[l+1]),ans += a[l+1];
			path[++cnt].push_back(1),path[cnt].push_back(a[l]),ans += a[l];
			path[++cnt].push_back(2),path[cnt].push_back(a[l]),path[cnt].push_back(a[l+2]),ans += a[l+2];
			last = 0;
		}
		else{
			if(a[l] + a[r-1] <= 2*a[l+1]){
				path[++cnt].push_back(2),path[cnt].push_back(a[l]),path[cnt].push_back(a[r]),ans += a[l+1];
				path[++cnt].push_back(1),path[cnt].push_back(a[l]),ans += a[l];
				path[++cnt].push_back(2),path[cnt].push_back(a[l]),path[cnt].push_back(a[r-1]),ans += a[r-1];
				path[++cnt].push_back(1),path[cnt].push_back(a[l]),ans += a[l];
				
			}
			else{
				path[++cnt].push_back(2),path[cnt].push_back(a[l]),path[cnt].push_back(a[l+1]),ans += a[l+1];
				path[++cnt].push_back(1),path[cnt].push_back(a[l]),ans += a[l];
				path[++cnt].push_back(2),path[cnt].push_back(a[r-1]),path[cnt].push_back(a[r]),ans += a[r];
				path[++cnt].push_back(1),path[cnt].push_back(a[l+1]),ans += a[l+1];
			}
			r -= 2;
			last -= 2;
		}
	}
	printf("%d\n",ans);
	for(int i = 1;i <= cnt;i++){
		printf("%d",path[i][0]);
		for(int j = 1;j <= path[i][0];j++) printf(" %d",path[i][j]);
		puts("");
	}
	return 0;
}
