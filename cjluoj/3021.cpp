#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int w[35][35],hp[35][35];
int HP,ans,sum;
int dx[2]={0,1};
int dy[2]={1,0};
int m,n;
bool flag;
void dfs(int xx,int yy)
{
        HP+=hp[xx][yy];
        sum+=w[xx][yy];
        if(HP<1) {HP-=hp[xx][yy];sum-=w[xx][yy];return;}
        else if(HP>100) HP=100;
        if(xx==m&&yy==n) {ans=max(ans,sum);flag=true;}
        for(int i=0;i<2;i++)
        {
                int tx=xx+dx[i];
                int ty=yy+dy[i];
                if(tx<=m&&ty<=n)
                {
                        dfs(tx,ty);
                }
        }
        HP-=hp[xx][yy];
        sum-=w[xx][yy];

}
int main()
{
        int i,j;
        int T;
        while(scanf("%d",&T)!=EOF)
        {
                int t;
                while(T--)
                {
                        scanf("%d%d",&m,&n);
                        for(i=1;i<=m;i++)
                                for(j=1;j<=n;j++)
                                {
                                        scanf("%d",&t);
                                        hp[i][j]=-t;
                                }
                        for(i=1;i<=m;i++)
                                for(j=1;j<=n;j++)
                                {
                                        scanf("%d",&t);
                                        hp[i][j]+=t;
                                }
                        for(i=1;i<=m;i++)
                                for(j=1;j<=n;j++)
                                        scanf("%d",&w[i][j]);
                        HP=100;
                        ans=sum=0;
                        flag=false;
                        dfs(1,1);
                        if(flag) printf("%d\n",ans);
                        else printf("Cannot finish the task!\n");
                }
        }
        return 0;
}
