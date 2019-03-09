#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int b[100005],seg[100005];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d",&b[0]);
	for(int i = 1;i < n;i++){
		scanf("%d",&b[i]);
		seg[i] = b[i] - b[i-1] - 1;
	}
	sort(seg+1,seg+n+1,greater<int>());
	int ans = b[n-1] - b[0] + 1;
	for(int i = 1 ;i < k;i++) ans -= seg[i]; 
	printf("%d\n",ans);
	return 0;
}
