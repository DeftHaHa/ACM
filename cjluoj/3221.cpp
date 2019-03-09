#include<cstdio>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int stkx[10005];
int stky[10005];
int top;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int maze[1005][1005];
bool vis[1005][1005];
int x2,y2;
bool flag;
void dfs(int x,int y)
{
        vis[x][y]=true;
        stkx[top]=x;
        stky[top]=y;
        top++;
        if(x==x2&&y==y2)
        {
                flag=true;
                printf("(%d,%d)",stkx[0],stky[0]);
                for(int j=1;j<top;j++)
                        printf("->(%d,%d)",stkx[j],stky[j]);
                cout<<endl;

        }
        for(int i=0;i<4;i++)
        {
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(!vis[tx][ty]&&maze[tx][ty]==1&&tx>=0&&ty>=0)
                {
                        dfs(tx,ty);
                }
        }
        vis[x][y]=false;
        top--;
}
int main()
{
        int N;
        int i,j;
        int x1,y1;
        int c=0;
        while(cin>>N)
        {
                memset(maze,0,sizeof(maze));
                for(i=0;i<N;i++)
                {
                        for(j=0;j<N;j++)
                        {
                                cin>>maze[i][j];
                        }
                }
                cin>>x1>>y1;
                cin>>x2>>y2;
                memset(vis,false,sizeof(vis));
                flag=false;
                top=0;
                printf("Case %d:\n",++c);
                dfs(x1,y1);
                if(!flag) cout<<"NO"<<endl;
                cout<<endl;
        }
        return 0;
}
