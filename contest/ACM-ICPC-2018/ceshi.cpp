#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int t,n,m;
long long maxSum,l,r,ans;
struct Edge{
    int v;
    long long w;
};
vector<Edge> e[100005];
Edge tempE;
bool vis[100005];
long long sumE[100005];
long long sumT[100005];
bool isok(long long x){
    for(int i=1;i<=n;i++) sumT[i]=sumE[i];
    memset(vis,false,sizeof(vis));
    bool flag=true;
    int re=n;
    while(flag){
        flag=false;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&sumT[i]<=x){
                re--;
                vis[i]=true;
                for(int j=0;j<e[i].size();j++){
                    if(!vis[e[i][j].v]) sumT[e[i][j].v]-=e[i][j].w;
                }
                flag=true;
            }
        }
    }
    return re==0;
}
long long xjb(long long l,long long r){
    if(l==r) return l;
    long long mid=(l+r)/2;
    if(isok(mid)){
        return xjb(l,mid);
    }else{
        return xjb(mid+1,r);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(sumE,0,sizeof(sumE));
        for(int i=1;i<=m;i++){
            int a,b;
            long long c;
            scanf("%d%d%lld",&a,&b,&c);
            sumE[a]+=c;
            sumE[b]+=c;
            tempE.v=b; tempE.w=c;
            e[a].push_back(tempE);
            tempE.v=a;
            e[b].push_back(tempE);
        }
        maxSum=0;
        for(int i=1;i<=n;i++)
            maxSum=max(maxSum,sumE[i]);
        l=0;r=maxSum;
        ans=xjb(l,r);
        printf("%lld\n",ans);
    }

    return 0;
}
