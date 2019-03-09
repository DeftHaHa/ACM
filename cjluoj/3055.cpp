#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
        char maze[105][105];
        int ans[105][105];
        int m,n;
        int i,j;
        int c=0;
        int dx[8]={0,0,1,-1,1,1,-1,-1};
        int dy[8]={1,-1,0,0,1,-1,-1,1};
        while(scanf("%d%d",&m,&n)!=EOF)
        {
                char ch=getchar();
                if(m==0&&n==0) break;
                memset(maze,0,sizeof(maze));
                memset(ans,0,sizeof(ans));
                for(i=1;i<=m;i++)
                {
                        for(j=1;j<=n;j++)
                        {
                                scanf("%c",&maze[i][j]);
                        }
                        ch=getchar();
                }
                for(i=1;i<=m;i++)
                {
                        for(j=1;j<=n;j++)
                        {
                                if(maze[i][j]=='*') ans[i][j]=-1;
                                else
                                        for(int k=0;k<8;k++)
                                        {
                                                int tx=i+dx[k];
                                                int ty=j+dy[k];
                                                if(maze[tx][ty]=='*') ans[i][j]++;
                                        }
                        }
                }
                printf("field #%d:\n",++c);
                for(i=1;i<=m;i++)
                {
                        for(j=1;j<=n;j++)
                        {
                                if(ans[i][j]==-1) printf("*");
                                else printf("%d",ans[i][j]);
                        }
                        printf("\n");
                }
                printf("\n");
        }
        return 0;
}
