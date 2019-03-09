#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
        int v,next;
        int id,id2;
}e[100005];
int eid;
int p[100005];
void addedge(int u,int v,int id,int id2)
{
        e[eid].v=v;
        e[eid].id=id;
        e[eid].id2=id2;
        e[eid].next=p[u];
        p[u]=eid++;
}
int dfn[10005],low[10005];
int father[10005];
int tim;
int scc;
int ans[10005],tot;
void tarjan(int u,int id)
{
        dfn[u]=low[u]=++tim;
        for(int i=p[u];i!=-1;i=e[i].next)
        {
                int v=e[i].v;
                if(!dfn[v])
                {
                        tarjan(v,e[i].id);
                        low[u]=min(low[u],low[v]);
                        if(low[v]>dfn[u])
                                ans[tot++]=e[i].id2;
                }
                else if(id/2!=e[i].id/2)
                {
                        low[u]=min(dfn[v],low[u]);
                }
        }
}
int main()
{
        int n,m;
        int a,b;
        while(cin>>n>>m)
        {
                if(n==0&&m==0) break;
                memset(p,-1,sizeof(p));
                eid=0;
                for(int i=1;i<=m;i++)
                {
                        cin>>a>>b;
                        addedge(a,b,(i-1)*2,i);
                        addedge(b,a,(i-1)*2+1,i);
                }
                memset(dfn,0,sizeof(dfn));
                memset(father,-1,sizeof(father));
                tot=0;
                tarjan(1,-2);
                if(tot==0) cout<<"No answer!"<<endl;
                else
                {
                        cout<<tot<<endl;
                        sort(ans,ans+tot);
                        cout<<ans[0];
                        for(int i=1;i<tot;i++)
                        {
                                cout<<' '<<ans[i];
                        }
                        cout<<endl;
                }
        }
        return 0;
}
