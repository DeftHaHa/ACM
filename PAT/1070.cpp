#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct MC{
	double cnt,p,w;
}mc[1005];
bool cmp(MC a,MC b){
	return a.w > b.w;
}
int main()
{
	int N;
	double D;
	scanf("%d%lf",&N,&D);
	for(int i = 0;i < N;i++) scanf("%lf",&mc[i].cnt);
	for(int i = 0;i < N;i++){
		scanf("%lf",&mc[i].p);
		mc[i].w = mc[i].p/mc[i].cnt;
	}
	sort(mc,mc+N,cmp);
	double ans = 0;
	for(int i = 0;i < N;i++){
		if(mc[i].cnt > D){
			ans += mc[i].w * D;
			D = 0;
		}
		else{
			ans += mc[i].p;
			D -= mc[i].cnt;
		}
		if(D == 0) break;
	}
	printf("%.2lf\n",ans);
	return 0;
}
