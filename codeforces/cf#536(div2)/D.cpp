#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
struct cmp{
	bool operator()(int a,int b){
		return a > b;
	}
};
priority_queue<int,vector<int>,cmp> q;
bool vis[100005];
int ans[100005],cnt = 0;
struct edge{
	int v,next;
}e[200005];
int p[200005],eid;
void addedge(int u,int v){
	e[eid].v = v;
	e[eid].next = p[u];
	p[u] = eid++;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(p,-1,sizeof(p));
	eid = 0;
	int u,v;
	while(m--){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	q.push(1);
	printf("1");
	vis[1] = true;
	bool f = false;
	while(!q.empty()){
		u = q.top();
		if(!f) f = true;	
		else printf(" %d",u);
		q.pop();
		for(int i=p[u];i!=-1;i=e[i].next){
			v = e[i].v;
			if(!vis[v]) q.push(v),vis[v] = true;
		}
	}
	puts("");
	return 0;
}
