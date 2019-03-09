#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
int a[200005];
int sum[200005];
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sum[0] = 0;
	sum[1] = a[1];
	for(int i = 2;i <= n;i++) sum[i] = sum[i-2]+a[i];
	int osum = sum[n-1],esum = sum[n];
	if(n&1) swap(osum,esum);
	int ans = 0;
	if(osum - a[1] == esum) ans++;
	for(int i = 2;i <= n;i++){
	 	if(i&1){
	 		int tesum = sum[i-1] + (osum - sum[i-2]) - a[i];
	 		int tosum = sum[i-2] + (esum - sum[i-1]);
	 		if(tesum == tosum)	ans++;
		}
		else{
			int tosum = sum[i-1] + (esum - sum[i-2]) - a[i];
			int tesum = sum[i-2] + (osum - sum[i-1]);
			if(tesum == tosum) ans++;
			
		}
	}
	printf("%d\n",ans);
	return 0;
}
