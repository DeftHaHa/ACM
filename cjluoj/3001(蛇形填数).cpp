#include<iostream>
#include<cstring>
using namespace std;
int main()
{
        int n;
        int ans[105][105];
        while(cin>>n)
        {
                if(n==0) break;
                int tot=1;
                memset(ans,0,sizeof(ans));
                ans[0][n-1]=1;
                int x=0,y=n-1;
                while(tot<n*n)
                {
                        while(x+1<n&&!ans[x+1][y]) ans[++x][y]=++tot;
                        while(y-1>=0&&!ans[x][y-1]) ans[x][--y]=++tot;
                        while(x-1>=0&&!ans[x-1][y]) ans[--x][y]=++tot;
                        while(y+1<n&&!ans[x][y+1])  ans[x][++y]=++tot;
                }
                for(int i=0;i<n;i++)
                {
                        cout<<ans[i][0];
                        for(int j=1;j<n;j++)
                        {
                                cout<<' '<<ans[i][j];
                        }
                        cout<<endl;
                }
        }
        return 0;
}
