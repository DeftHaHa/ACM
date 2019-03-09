#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct Edge{
	int v,next,line;
}e[20005];
int p[20005],eid = 0;
void addedge(int u,int v,int line){
	e[eid].v = v;
	e[eid].line = line;
	e[eid].next = p[u];
	p[u] = eid++;
}
struct Path{
	int line,u;
}path[20005],ans[20005];
int s[105];
bool vis[100005];
int st,en;
int Mind = 0x3f3f3f3f,Minc = 0x3f3f3f3f;
void Print (Path ans[]){
	printf("%d\n",Mind);
	int flag = 0,last = st;
	ans[Mind+1].line = -1;
	for(int i = 1;i <= Mind;i++){
		//cout<<"#"<<ans[i].u<<' '<<ans[i].line<<endl;
		if(ans[i].line == ans[i+1].line) continue;
		else{
			printf("Take Line#%d from %04d to %04d.\n",ans[i].line,last,ans[i].u);
			last = ans[i].u;
			flag = 1;
		}
	}
	if(!flag) printf("Take Line#%d from %04d to %04d.\n",ans[1].line,st,en);
}
void dfs(int u,int d,int c,int line){
	if(d>Mind) return;
	path[d].u = u;
 	path[d].line = line;
	if(u == en){
		if(d < Mind || (d==Mind && c < Minc)){
			Mind = min(Mind,d);
			Minc = min(Minc,c);
			for(int i = 0;i <= d;i++) ans[i] = path[i];
		}
		return;
	}
	vis[u] = true;
	for(int i = p[u];i!=-1;i=e[i].next){
		if(!vis[e[i].v]){
			dfs(e[i].v,d+1,c+(e[i].line != line),e[i].line);
		}
	}
	vis[u] = false;
}
int main()
{
	int N,M;
	scanf("%d",&N);
	eid = 0;
	memset(p,-1,sizeof(p));
	for(int i = 1;i <= N;i++){
		scanf("%d",&M);
		scanf("%d",&s[1]);
		for(int j = 2;j <= M;j++){
			scanf("%d",&s[j]);
			addedge(s[j-1],s[j],i);
			addedge(s[j],s[j-1],i);
		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&st,&en);
		memset(vis,false,sizeof(vis));
		Mind = 0x3f3f3f3f,Minc = 0x3f3f3f3f;
		dfs(st,0,0,-1);
		Print(ans);
	}
	return 0;
}
