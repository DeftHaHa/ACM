#include<cstdio>  
#include<cstring>  
#include<vector>  
#include<algorithm>  
#include<iostream>
using namespace std;  
const int maxn=5000+5;  
int n,m;  
vector<int> G[maxn];  
int dfs_clock;  
int pre[maxn],low[maxn],cut[maxn];  
int tarjan(int u,int fa,int forbid)
{  
    int lowu=pre[u]=++dfs_clock;  
    int child=0;  
    for(int i=0;i<G[u].size();i++)  
    {  
        int v=G[u][i];  
        if(v==fa||v==forbid) continue;  
        if(!pre[v])  
        {  
            child++;  
            int lowv=tarjan(v,u,forbid);  
            lowu=min(lowu,lowv);  
            if(lowv >= pre[u])  
                cut[u]++;  
        }  
        else lowu=min(lowu,pre[v]);  
    }  
    if(fa<0) cut[u]--;  
    return low[u]=lowu;  
}  
int main()  
{  
    while(scanf("%d%d",&n,&m)==2)  
    {  
        for(int i=0;i<n;i++) G[i].clear();  
        for(int i=0;i<m;i++)  
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            G[u].push_back(v);  
            G[v].push_back(u);  
        }  
        int ans=-100;  
        for(int u=0;u<n;u++)  
        {  
            int sum=0;
            dfs_clock=0;  
            memset(pre,0,sizeof(pre));  
            memset(cut,0,sizeof(cut));  
            for(int v=0;v<n;v++)if(v!=u && !pre[v])  
            {  
                sum++;  
                tarjan(v,-1,u);  
            }  cout<<u<<' '<<sum<<endl;
            for(int v=0;v<n;v++){
            	ans = max(ans,sum+cut[v]); cout<<cut[v]<<' ';
			}cout<<endl;
                 
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
/*
6 7
0 1
0 2
1 2
1 3
3 4
3 5
4 5
*/
