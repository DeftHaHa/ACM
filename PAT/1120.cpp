#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
int cnt[40];
int f(int n){
	int res = 0;
	while(n){
		res+=n%10;
		n/=10;
	}
	return res;
}
int main()
{
	int N,x;
	scanf("%d",&N);
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i < N;i++){
		scanf("%d",&x);
		a.push_back(x);
		cnt[f(x)]++;
	}
	int ans[40],t = 0;
	for(int i = 0;i < 40;i++){
		if(cnt[i]) ans[t++] = i;
	}
	printf("%d\n%d",t,ans[0]);
	for(int i = 1;i < t;i++) printf(" %d",ans[i]);
	puts("");
	return 0;
}
