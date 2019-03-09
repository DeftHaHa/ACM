#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int N,M,T;
bool vis[25][25];
bool arrive;
pair<int,int> q[405];
int step[25][25];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char maze[25][25];
void bfs(int sx,int sy)
{
        memset(vis,false,sizeof(vis));
        step[sx][sy]=0;
        arrive=false;
        int head,tail;
        head=tail=0;
        q[0].first=sx;
        q[0].second=sy;
        tail++;
        while(head<tail)
        {
                int nowx=q[head].first;
                int nowy=q[head].second;
                head++;
                vis[nowx][nowy]=true;
                for(int i=0;i<4;i++)
                {
                        int tx=nowx+dx[i];
                        int ty=nowy+dy[i];
                        if(maze[tx][ty]=='D')
                        {
                                int Time=step[nowx][nowy]+1;
                                if(Time<=T&&(T-Time)%2==0)
                                {
                                        arrive=true;
                                        return;
                                }
                        }
                        else if(!vis[tx][ty]&&maze[tx][ty]=='.')
                        {
                                q[tail].first=tx;
                                q[tail].second=ty;
                                step[tx][ty]=step[nowx][nowy]+1;
                                tail++;
                        }
                }
        }
}
int main()
{
        int i,j;
        int sx,sy;
        while(cin>>N>>M>>T)
        {
                char ch=getchar();
                if(N==0&&M==0&&T==0) break;
                for(i=1;i<=N;i++)
                {
                        for(j=1;j<=M;j++)
                        {
                                cin>>maze[i][j];
                                if(maze[i][j]=='S')
                                {
                                        sx=i;
                                        sy=j;
                                }
                        }
                }
                bfs(sx,sy);
                if(arrive) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
        }
        return 0;
}
