#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n,m;
struct Dish{
	int id;
	ll c;
}dish[100005];
int a[100005],c[100005];
bool cmp(Dish a,Dish b){
	if(a.c!=b.c) return a.c<b.c;
	return a.id < b.id;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%I64d",&a[i]);
	for(int i = 1;i <= n;i++){
		scanf("%I64d",&c[i]);
		dish[i].id = i;
		dish[i].c = c[i];
	}
	sort(dish+1,dish+n+1,cmp);
	int pos = 1;
	int t,d;
	for(int i = 0;i < m;i++){
		scanf("%d%d",&t,&d);
		ll sum = 0;
		int cnt = 0;
		int x = min(d,a[t]);
		a[t] -= x;
		d -= x;
		sum += x*c[t];
		bool ok = true;
		while(d>0 && ok){
			for(;pos <= n;pos++){
				if(a[dish[pos].id] > 0) break;
			}
			if(pos > n||a[dish[pos].id] == 0) ok = false;
			else{
				x = min(d,a[dish[pos].id]);
				d -= x;
				a[dish[pos].id] -= x;
				sum += x*c[dish[pos].id];
			}
		}
		//cout<<"====";for(int i = 1;i <= n;i++) cout<<a[i]<<" ";cout<<endl;
		if(!ok) puts("0");
		else printf("%I64d\n",sum);
	}
	return 0;
}
/*
8 5
8 6 2 1 4 5 7 5
6 3 3 2 6 2 3 2
2 100
1 4
4 7
3 4
6 10
*/
