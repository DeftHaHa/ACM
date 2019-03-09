#include<iostream>
#include<cstdio>
#include<stack>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=10005,maxm=200005;
struct edge
{
	int u,v,next;
}e[maxm];
int p[maxm],eid;
void addedge(int u,int v)
{
	e[eid].u=u;
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int dfn[maxn],low[maxn],idx;
stack<edge> S;
set<int> bcc;
int b_cnt,ans2;
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++idx;
	for(int i=p[u];i!=-1;i=e[i].next)
	{
		int v=e[i].v;
		if((i^1)==fa) continue;
		if(!dfn[v])
		{
			S.push(e[i]);
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])    //��� 
			{
				int cnt=0;
				bcc.clear();
				edge temp;
				do
				{
					cnt++;
					temp=S.top();
					S.pop();
					bcc.insert(temp.v);
					bcc.insert(temp.u);
				}while(temp.u!=u||temp.v!=v); //ע���ǻ� 
				if(cnt>bcc.size()) ans2+=cnt; //��ͨ�����ڱ������ڵ��� 
				// cout<<'#'<<cnt<<' '<<bcc.size()<<endl;
			}
			if(low[v]>dfn[u]) b_cnt++; //�� 
		}   
		else if(dfn[v]<dfn[u])  //������������,��ֹ��ķ����ı߼��� 
		{
			S.push(e[i]);
			low[u]=min(dfn[v],low[u]);
		}
	}
}
int main()
{
	int N,M;
	while(~scanf("%d%d",&N,&M))
	{
		if(!N&&!M) return 0;
		int u,v;
		eid=0;
		memset(p,-1,sizeof(p));
		while(M--)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		idx=0;
		for(int i=0;i<=N;i++) dfn[i]=0;
		idx=b_cnt=ans2=0;
		while(!S.empty()) S.pop();
		for(int i=0;i<N;i++)
		{
			if(!dfn[i]) tarjan(i,-1);
		}
		printf("%d %d\n",b_cnt,ans2);
	}
	return 0;
}
