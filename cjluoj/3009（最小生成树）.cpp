#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
        int u,v,w;
}e[100005];
int father[1005];
int get(int x)
{
        if(father[x]==x) return x;
        else return father[x]=get(father[x]);
}
void merge(int a,int b)
{
        a=get(a);
        b=get(b);
        if(a!=b)
                father[a]=b;
}
bool cmp(const edge &a,const edge &b)
{
        return a.w<b.w;
}
int main()
{
        int N;
        int i,j;
        int Q;
        int t;
        while(cin>>N)
        {
                int eid=0;
                for(i=1;i<=N;i++)
                {
                        for(j=1;j<=N;j++)
                        {
                                cin>>t;
                                if(j>i)
                                {
                                        e[eid].u=i;
                                        e[eid].v=j;
                                        e[eid].w=t;
                                        eid++;
                                }
                        }
                }
                for(i=1;i<=N;i++) father[i] = i;
                cin>>Q;
                int uu,vv;
                while(Q--)
                {
                        cin>>uu>>vv;
                        merge(uu,vv);
                }
                sort(e,e+eid,cmp);
                int ans=0;
                for(i=0;i<eid;i++)
                {
                        int af=get(e[i].u);
                        int as=get(e[i].v);
                        if(af!=as)
                        {
                                merge(af,as);
                                ans+=e[i].w;
                        }

                }
                cout<<ans<<endl;
        }
        return 0;
}
