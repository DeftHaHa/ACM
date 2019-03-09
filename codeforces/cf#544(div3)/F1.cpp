#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
struct edge{
	int u,v,next;
}e[400005];
int p[400005],eid = 0;
bool vis[200005],chose[400005];
void addedge(int u,int v){
	e[eid].u = u;
	e[eid].v = v;
	e[eid].next = p[u];
	p[u] = eid++;
}
int d[200005];
queue<int> q;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	memset(p,-1,sizeof(p));
	memset(d,0,sizeof(d));
	for(int i = 0;i < m;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
		d[u]++;
		d[v]++;
	}
	int maxd = 0;
	for(int i = 1;i <= n;i++){
		if(d[i] > maxd) maxd = d[i],u = i;
	}
	memset(vis,false,sizeof(vis));
	memset(chose,false,sizeof(chose));
	vis[u] = true;
	for(int i = p[u];i != -1;i=e[i].next){
		int v = e[i].v;
		chose[i] = true;
		vis[v] = true;
		q.push(v);
	}
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i = p[u];i != -1;i=e[i].next){
			v = e[i].v;	
			if(!vis[v]){
				vis[v] = true;
				chose[i] = true;
				q.push(v);
			}
		}
	}
	for(int i = 0;i < eid;i++){
		if(chose[i]){
			printf("%d %d\n",e[i].u,e[i].v);
		}
	}
	return 0;
}
