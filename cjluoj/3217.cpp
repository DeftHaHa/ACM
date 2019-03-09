#include<iostream>
#include<cstring>
using namespace std;
int row;
bool vis1[105],vis2[105],colum[105];
int ans;
int n;
void dfs(int row)
{
        if(row==n) {ans++;return;}
        for(int i=1;i<=n;i++)
        {
                if(!vis1[i+row]&&!vis2[n+i-row]&&!colum[i])
                {
                        vis1[i+row]=true;
                        vis2[n+i-row]=true;
                        colum[i]=true;
                        dfs(row+1);
                        vis1[i+row]=false;
                        vis2[n+i-row]=false;
                        colum[i]=false;
                }

        }
}
int main()
{
        while(cin>>n)
        {
                if(n==0) break;
                memset(vis1,false,sizeof(vis1));
                memset(vis2,false,sizeof(vis2));
                memset(colum,false,sizeof(colum));
                ans=0;
                row=0;
                dfs(0);
                cout<<ans<<endl;
        }
        return 0;
}
