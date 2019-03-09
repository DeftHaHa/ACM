#include<iostream>
#include<cstring>
using namespace std;
char s[105][105];
bool vis[105][105];
int mx[4]={1,-1,0,0};
int my[4]={0,0,1,-1};
int ans;
void dfs(int x,int y)
{
    int i,j;
    vis[x][y]=true;
    cout<<x<<' '<<y<<endl;
    for(i=0;i<4;i++)
    {
        int xx=x+mx[i];
        int yy=y+my[i];
        if(s[xx][yy]=='#'&&!vis[xx][yy]) dfs(xx,yy);
    }
    return;

}
int main()
{
    int n,m;
    int i,j;
    while(cin>>n>>m)
    {
        memset(s,0,sizeof(s));
        memset(vis,false,sizeof(vis));
        ans=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>s[i][j];
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i][j]!='#') vis[i][j]=true;
                else if(s[i][j]=='#'&&!vis[i][j])
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
