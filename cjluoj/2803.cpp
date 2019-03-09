#include<iostream>
#include<cstring>
using namespace std;
int re[105][105];
int father[105];
int get(int x)
{
        if(father[x]==x) return x;
        else return father[x]=get(father[x]);
}
void Merge(int a,int b)
{
        a=get(a);
        b=get(b);
        if(a!=b)
                father[a]=b;
}
int main()
{
        int n,m,k;
        while(cin>>n>>m>>k)
        {
                int u,v,w;
                for(int i=1;i<=n;i++) father[i]=i;
                memset(re,0,sizeof(re));
                while(m--)
                {
                        cin>>u>>v>>w;
                        if(w==1) Merge(u,v);
                        else if(w==-1)
                        {
                                re[u][v]=-1;
                                re[v][u]=-1;
                        }
                }
                while(k--)
                {
                        cin>>u>>v;
                        int fu=get(u);
                        int fv=get(v);
                        if(fu==fv)
                        {
                                if(re[u][v]!=-1)
                                        cout<<"No problem"<<endl;
                                else if(re[u][v]==-1)
                                        cout<<"OK but..."<<endl;
                        }
                        else
                        {
                                if(re[u][v]!=-1)
                                        cout<<"OK"<<endl;
                                else if(re[u][v]==-1)
                                        cout<<"No way"<<endl;
                        }
                }
        }
        return 0;
}
