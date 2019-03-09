#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct Node{
	int l,r,dfn,id;
	Node(){l = r = -1;}
}node[25];
int bfs(int root)
{
	node[root].dfn = node[root].id = 1;
	queue<Node> q;
	q.push(node[root]);
	int dfn = 1,last;
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		if(now.l != -1){
			node[now.l].dfn = ++dfn;
			node[now.l].id = now.id*2;
			if(node[now.l].dfn != node[now.l].id) return -1;
			q.push(node[now.l]);
			last = now.l;	
		}	
		if(now.r != -1){
			node[now.r].dfn = ++dfn;
			node[now.r].id = now.id*2+1;
			if(node[now.r].dfn != node[now.r].id) return -1;
			q.push(node[now.r]);	
			last = now.r;
		}	
	}
	return last;
}
int main()
{
	int N;
	scanf("%d",&N);
	int u,v;
	char su[5],sv[5];
	int fa[25];
	memset(fa,-1,sizeof(fa));
	for(int i = 0;i < N;i++){
		scanf("%s%s",su,sv);
		if(su[0]!='-'){
			sscanf(su,"%d",&u);
			node[i].l = u;
			fa[u] = i;
		}
		if(sv[0]!='-'){
			sscanf(sv,"%d",&v);
			node[i].r = v;
			fa[v] = i;
		}
	}
	int root = -1;
	for(int i = 0;i < N;i++){
		if(fa[i]==-1){
			root = i;
			break;
		}
	}
	int ok = bfs(root);
	if(ok == -1) printf("NO %d\n",root);
	else printf("YES %d\n",ok);
	return 0;
} 
