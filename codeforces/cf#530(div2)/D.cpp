#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int n;
struct edge{
	int v,next;
}e[200005];
int p[200005],eid;
int s[200005],a[200005];
void addedge(int u,int v){
	e[eid].v = v;
	e[eid].next = p[u];
	p[u] = eid++;
}
long long SUM;
bool flag;
int getMin(int u)
{
	int res = 1e9+7;
	for(int i = p[u];i != -1;i = e[i].next){
		int v = e[i].v;
		res = min(res,s[v]);
	}
	return res;
} 
void dfs(int u){
	for(int i = p[u];i != -1;i = e[i].next){
		int v = e[i].v;
		int Min = getMin(v);
		if(Min < s[u]) flag = false;
		if(Min > 1e9) a[v] = 0;
		else
		{
			a[v] = Min - s[u];
			s[v] = a[v] + s[u];
			//cout<<"#####"<<v<<' '<<a[v]<<endl;
			for(int j = p[v];j != -1;j = e[j].next){
				int tv = e[j].v;
				a[tv] = s[tv] - s[v];
				dfs(tv);
			}
		}
	}
}
int main()
{
	cin>>n;
	memset(p,-1,sizeof(p));
	eid = 0;
	int v;
	for(int i = 2;i <= n;i++){
		scanf("%d",&v);
		addedge(v,i);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&s[i]);
	}
	a[1] = s[1];
	flag = true;
	dfs(1);
	if(flag){
		SUM = 0;
		for(int i = 1;i <= n;i++){
			SUM += a[i]; //cout<<a[i]<< ' ';
		}
		cout<<SUM<<endl;
	}
	else cout<<-1<<endl;
	return 0;
} 
