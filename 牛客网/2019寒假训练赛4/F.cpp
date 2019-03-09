#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int fa[100005];
int get(int x){
	return fa[x] == x ? x : get(fa[x]);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) fa[i] = i;
	int a,b;
	while(m--){
		scanf("%d%d",&a,&b);
		int aa = get(a),bb = get(b);
		
		
	}
	return 0;
}
