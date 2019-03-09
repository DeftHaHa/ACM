#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX_N = 200005;
const int MAX_M = 200005;
struct edge {
    int v, next;
} e[MAX_M];
int p[MAX_N], eid;
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int dfn[MAX_N], low[MAX_N];
int idx = 0; 
int belong[MAX_N], scc = 0;
int s[MAX_N], top = 0; 
bool in_stack[MAX_N];

int ans=0x3f3f3f3f;
void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    s[top++] = u;
    in_stack[u] = true;   //cout<<"-->"<<u<<endl;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);

        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);

        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        int cnt=0;
        do {
            belong[s[--top]] = scc;
            cnt++;
            in_stack[s[top]] = false;
        } while (s[top] != u);
        //cout<<scc<<"="<<cnt<<endl;
        if(cnt>2) ans=min(ans,cnt);
    }
}


int main()
{
	memset(dfn,0,sizeof(dfn));
	memset(p,-1,sizeof(p));
	eid=0;
	scc=0;
	idx=0;
	top=0;
	int N;
	cin>>N;
	int n;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&n);
		addedge(i,n);
	}	
	for(int i=1;i<=N;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
    cout<<ans<<endl;
}




