#include<cstring>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
char maze[100][100];
bool vis[100][100];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int step[100][100];
int k;
pair<int,int> q[100005][50];
queue<int> now;
int top,behind;
void bfs()
{
        vis[q[0][0].first][q[0][0].second]=true;
        now.push(0);
        while(!now.empty())
        {
                int top=now.front();
                int nowx=q[top][0].first;
                int nowy=q[top][0].second;
                now.pop();
                for(int i=0;i<4;i++)
                {
                        bool go=true,arrive=false;
                        behind++;
                        for(int j=0;j<k;j++)
                        {

                                q[behind][j].first=q[top][j].first+dx[i];
                                q[behind][j].second=q[top][j].second+dy[i];
                                if(maze[q[behind][j].first][q[behind][j].second]=='.')  continue;
                                else if(maze[q[behind][j].first][q[behind][j].second]=='A') arrive=true;
                                else
                                {
                                        go=false;
                                        break;
                                }
                        }
                        if(go&&arrive)
                        {
                                cout<<step[nowx][nowy]+1<<endl;
                                return;

                        }
                        else if(go&&!vis[q[behind][0].first][q[behind][0].second])
                        {
                                step[q[behind][0].first][q[behind][0].second]=step[nowx][nowy]+1;
                                vis[q[behind][0].first][q[behind][0].second]=true;
                                now.push(behind);
                        }
                }
        }
        cout<<"Impossible"<<endl;
}
int main()
{
        int m,n;
        int i,j;
        int sx,sy;
        while(cin>>m>>n)
        {
                char ch=getchar();
                memset(maze,0,sizeof(maze));
                memset(vis,false,sizeof(vis));
                memset(step,0,sizeof(step));
                k=0;
                for(i=1;i<=n;i++)
                {
                        for(j=1;j<=m;j++)
                        {
                                cin>>maze[i][j];
                                if(maze[i][j]=='M')
                                {
                                        q[0][k].first=i;
                                        q[0][k].second=j;
                                        maze[i][j]='.';
                                        k++;
                                }
                        }
                }
                behind=0;
                bfs();
                while(!now.empty()) now.pop();
        }
        return 0;
}
