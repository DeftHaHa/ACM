#include<iostream>
#include<cstring>
using namespace std;
int maze[10][10];
bool visp[10][10];
bool visbox[10][10];
int ex,ey;
int psx,psy,pex,pey;
int qx[1005],qy[1005];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool bfsp(int px,int py)
{
        int ptail=0,phead=0;
        memset(visp,false,sizeof(visp));
        qx[ptail]=px;
        qy[ptail]=py;
        ptail++;
        visp[px][py]=true;
        while(phead<ptail)
        {
                int nowx=qx[phead];
                int nowy=qy[phead];
                phead++;
                for(int j=0;j<4;j++)
                {
                        int xx=nowx+dx[j];
                        int yy=nowy+dy[j];
                        if(!visp[xx][yy]&&maze[xx][yy]==0)
                        {
                                if(xx==pex&&yy==pey) return true;
                                qx[ptail]=xx;
                                qy[ptail]=yy;
                                visp[xx][yy]=true;
                                ptail++;
                        }
                }
        }
        return false;
}
int step[10][10];
int quex[1005],quey[1005];
void bfs(int sx,int sy)
{
        memset(visbox,false,sizeof(visbox));
        int head=0,tail=0;
        quex[tail]=sx;
        quey[tail]=sy;
        tail++;
        step[sx][sy]=0;
        visbox[sx][sy]=true;
        while(head<tail)
        {
                int nx=quex[head];
                int ny=quey[head];
                head++;
                maze[nx][ny]=1;
                for(int i=0;i<4;i++)
                {
                        int tx=nx+dx[i];
                        int ty=ny+dy[i];
                        if(!visbox[tx][ty]&&maze[tx][ty]==0)
                        {
                                pex=nx-dx[i];
                                pey=ny-dy[i];
                                if(bfsp(psx,psy))
                                {
                                        quex[tail]=tx;
                                        quey[tail]=ty;
                                        tail++;
                                        step[tx][ty]=step[nx][ny]+1;
                                        visbox[tx][ty]=true;
                                        if(tx==ex&&ty==ey)
                                        {
                                                cout<<step[tx][ty]<<endl;
                                                return;
                                        }

                                }
                        }
                }
                maze[nx][ny]=0;
                psx=nx;
                psy=ny;
        }
        cout<<-1<<endl;
        return;
}
int main()
{
        int i,j;
        int T;
        int M,N;
        int sx,sy;
        cin>>T;
        while(T--)
        {
                cin>>M>>N;
                memset(maze,-1,sizeof(maze));
                for(i=1;i<=M;i++)
                {
                        for(j=1;j<=N;j++)
                        {
                                cin>>maze[i][j];
                                if(maze[i][j]==2)
                                {
                                        sx=i;
                                        sy=j;
                                        maze[i][j]=0;
                                }
                                else if(maze[i][j]==3)
                                {
                                        ex=i;
                                        ey=j;
                                        maze[i][j]=0;
                                }
                                else if(maze[i][j]==4)
                                {
                                        psx=i;
                                        psy=j;
                                        maze[i][j]=0;
                                }
                        }
                }
                bfs(sx,sy);

        }
        return 0;
}

