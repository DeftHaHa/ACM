#include<iostream>
#include<cstring>
using namespace std;
int maze[1005][1005];
bool vis[1005][1005];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int x2,y2;
bool flag;
void dfs(int x,int y)
{
        vis[x][y]=true;
        if(x==x2&&y==y2) {flag=true;return;}
        for(int i=0;i<4;i++)
        {
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(maze[tx][ty]==1&&!vis[tx][ty]&&tx>=0&&ty>=0) dfs(tx,ty);
        }
        vis[x][y]=false;
}
int main()
{
        int x1,y1;
        int N;
        while(cin>>N)
        {
                memset(maze,0,sizeof(maze));
                for(int i=0;i<N;i++)
                {
                        for(int j=0;j<N;j++)
                        {
                                cin>>maze[i][j];
                        }
                }
                cin>>x1>>y1;
                cin>>x2>>y2;
                memset(vis,false,sizeof(vis));
                flag=false;
                dfs(x1,y1);
                if(flag) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
        }
        return 0;
}


