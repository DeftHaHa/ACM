#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int N,M;
int SA,EN;
struct Edge{
	int v,l,t,next;
}e[500005];
int eid,p[500005];
void addedge(int u,int v,int l,int t){
	e[eid].v = v;
	e[eid].l = l;
	e[eid].t = t;
	e[eid].next = p[u];
	p[u] = eid++;
}
int D[505],T[505],C[505],path[505];
int ans1[505],ans2[505],cnt1,cnt2;
bool vis[505];
struct cmp1{
	bool operator()(int a,int b){
		if(D[a]!=D[b]) return D[a] > D[b];
		return T[a] > T[b];
	}
};

void dijkstra1(){
	priority_queue<int,vector<int>,cmp1> q;
	memset(D,0x3f,sizeof(D));
	memset(T,0x3f,sizeof(T));
	memset(path,-1,sizeof(path));
	memset(vis,false,sizeof(vis));
	D[SA] = T[SA] = 0;
	q.push(SA);
	while(!q.empty()){
		int u = q.top();
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = p[u];i != -1;i = e[i].next){
			int v = e[i].v;
			if(!vis[v]&&(  D[u] + e[i].l < D[v] || D[u]+e[i].l == D[v] && T[u]+e[i].t < T[v])){
				D[v] = D[u] + e[i].l;
				T[v] = T[u] + e[i].t;
				path[v] = u;
				q.push(v);
			}
		}
	}
	cnt1 = 0;
	int now = EN;
	while(1){
		ans1[cnt1++] = now;
		if(now == SA) break;
		now = path[now];
	}
}
struct cmp2{
	bool operator()(int a,int b){
		if(T[a]!=T[b]) return T[a] > T[b];
		return C[a] > C[b];
	}
};
void dijkstra2(){
	priority_queue<int,vector<int>,cmp2> q;
	memset(T,0x3f,sizeof(T));
	memset(C,0x3f,sizeof(C));
	memset(path,-1,sizeof(path));
	memset(vis,false,sizeof(vis));
	T[SA] = C[SA] = 0;
	q.push(SA);
	while(!q.empty()){
		int u = q.top();
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = p[u];i != -1;i = e[i].next){
			int v = e[i].v;
			if(!vis[v] &&( T[u] + e[i].t < T[v] || T[u]+e[i].t == T[v] && C[u]+1 < C[v])){
				T[v] = T[u] + e[i].t;	
				C[v] = C[u] + 1;
				path[v] = u;
				q.push(v);
			}
		}
	}
	cnt2 = 0;
	int now = EN;
	while(1){
		ans2[cnt2++] = now;
		if(now == SA) break;
		now = path[now];
	}

}
int main()
{
	int u,v,ow,l,t;
	scanf("%d%d",&N,&M);
	eid = 0;
	memset(p,-1,sizeof(p));
	for(int i = 0;i < M;i++){
		scanf("%d%d%d%d%d",&u,&v,&ow,&l,&t);
		addedge(u,v,l,t);
		if(!ow) addedge(v,u,l,t);
	}
	scanf("%d%d",&SA,&EN);
	dijkstra1();
	dijkstra2();
	bool Same = true;
	if(cnt1 != cnt2) Same = false;
	if(Same)
		for(int i = 0;i < cnt1;i++) {
			if(ans1[i] != ans2[i]){
				Same = false;
				break;
			}
		}
	if(!Same){
		printf("Distance = %d: %d",D[EN],SA);
		for(int i = cnt1-2;i >= 0;i--) printf(" -> %d",ans1[i]);
		puts("");
		printf("Time = %d: %d",T[EN],SA);
		for(int i = cnt2-2;i >= 0;i--) printf(" -> %d",ans2[i]);
		puts("");
	}
	else{
		printf("Distance = %d; Time = %d: %d",D[EN],T[EN],SA);
		for(int i = cnt1-2;i >= 0;i--) printf(" -> %d",ans1[i]);
		puts("");
	}
	
	return 0;
}
