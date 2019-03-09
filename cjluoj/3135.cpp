#include<iostream>
#include<cstring>
using namespace std;
int n,m;
bool vis[100005];
int step[1000005];
int head,tail;
int q[1000005];
void bfs(int start)
{
        memset(vis,false,sizeof(vis));
        step[start]=0;
        head=tail=0;
        vis[start]=true;
        q[tail]=start;
        tail++;
        while(head<tail)
        {
                int now=q[head];
                head++;  //cout<<now<<endl;
                int temp=now+13;
                if(temp<=100000&&!vis[temp])
                {
                        q[tail]=temp;
                        step[temp]=step[now]+1;
                        if(temp==m)
                        {
                                cout<<step[temp]<<endl;
                                return;
                        }
                        tail++;
                }
                temp=now-12;
                if(temp>=0&&!vis[temp])
                {
                        q[tail]=temp;
                        step[temp]=step[now]+1;
                        if(temp==m)
                        {
                                cout<<step[temp]<<endl;
                                return;
                        }
                        tail++;
                }
                temp=now*2;
                if(temp<=100000&&!vis[temp])
                {
                        q[tail]=temp;
                        step[temp]=step[now]+1;
                        if(temp==m)
                        {
                                cout<<step[temp]<<endl;
                                return;
                        }
                        tail++;
                }
        }

}
int main()
{

        while(cin>>n>>m)
        {
                bfs(n);
        }
        return 0;
}
