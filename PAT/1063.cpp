#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<set> 
using namespace std;
int cnt[55];
set<int> Set[55];
int main()
{
	int N,M,num;
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		scanf("%d",&M);
		while(M--){
			scanf("%d",&num);
			Set[i].insert(num);
		}
	}
	int K,a,b;
	scanf("%d",&K);
	while(K--){
		scanf("%d%d",&a,&b);
		int tot = 0;
		//如果用两个几集合合并那么会被卡常数 
		for(set<int>::iterator it = Set[a].begin();it != Set[a].end();it++){
			if(Set[b].count(*it)){
				tot++;
			}
		}
		int cnta = Set[a].size(),cntb = Set[b].size();
		//printf("%d %d %d\n",cnta,cntb,tot);
		printf("%.1lf%%\n",(double)tot/(cnta+cntb-tot)*100.0);
	}
	return 0;
}
