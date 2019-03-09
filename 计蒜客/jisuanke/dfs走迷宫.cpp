#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int mx[4]={1,-1,0,0};
int my[4]={0,0,1,-1};
char maze[15][15];
bool vis[15][15];
int ans=0;
void dfs(int x,int y)
{
    if(maze[x][y]=='T')
    {
        ans++; cout<<"--->T"<<endl;
        return ;
    }
    else
    {
        vis[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int tx=x+mx[i];
            int ty=y+my[i];
            if(!vis[tx][ty]&&maze[tx][ty]!='#') {printf("->(%d,%d)\n",tx,ty);dfs(tx,ty);}
        }
        vis[x][y]=false;
    }
}
int main()
{

    int i,j;
    int n,m;
    char ch;
    int sx,sy;
    memset(vis,false,sizeof(vis));
    memset(maze,'#',sizeof(maze));
    while(cin>>n>>m)
    {
        ans=0;
        ch=getchar();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>maze[i][j];
                if(maze[i][j]=='S')
                {
                        sx=i;sy=j;
                }
            }
            ch=getchar();
        }
        dfs(sx,sy);
        printf("%d\n",ans);
        memset(vis,false,sizeof(vis));
        memset(maze,'#',sizeof(maze));
    }
    return 0;
}
