#include<iostream>
#include<cstring>
using namespace std;
long long p[50];
bool vis[50];
bool flag;
long long sum;
int tot;
long long m;
int n,k;
void dfs(int now)
{

    if(sum>m||tot>k||tot>n) return;

    else
    {
         sum+=p[now];
         if(sum==m&&tot==k) cout<<"*****"<<endl;
         tot++;
         int i;
         vis[now]=true;
         for(i=now;i<=n;i++)     ///i=now这样可以放置一个方案搜索多次，保证的搜索的顺序是从小到大，如果不这样写，那么一个方案是会被搜索阶乘次数的。
            if(!vis[i])
        {
                 cout<<sum<<'+'<<p[i]<<'='<<sum+p[i]<<' '<<tot<<endl;
                dfs(i);
            }
         tot--;
         sum-=p[now];
         vis[now]=false;
    }
}
int main()
{
    int i;
    while(cin>>m>>n>>k)
    {
        flag=false;
        sum=0;
        tot=0;
        memset(vis,false,sizeof(vis));
        memset(p,0,sizeof(p));
        for(i=1;i<=n;i++)
            cin>>p[i];
        dfs(0);
        if(flag)  cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
