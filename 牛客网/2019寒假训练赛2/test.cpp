#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a,t;
vector<vector<int> >tmp;
int Map[1000][1000],vis[1000][1000],fx[4][2]={{1,0},{0,1},{0,-1},{-1,0}},n,m,temp_dp,min_dp;
void dfs(int x,int y){
    int x1,y1;
    if(x==n-1&&y==m-1){
        tmp.push_back(a);
        return;
    }
    if(x<0||y<0||x>=n||y>=n)return;
    for(int i=0;i<4;i++){
        x1=x+fx[i][0];
        y1=y+fx[i][1];
        if(x1>=0&&y>=0&&x1<n&&y1<m&&vis[x1][y1]==0){
            vis[x1][y1]=1;
            a.push_back(Map[x1][y1]);
            dfs(x1,y1);
            vis[x1][y1]=0;
            a.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>m;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>Map[j][k];
                vis[j][k]=0;
            }
        }
        a.clear();
        tmp.clear();
        t.clear();
        a.push_back(Map[0][0]);
        dfs(0,0);
        for(auto it = t.begin();it!=t.end();it++){
            temp_dp=min_dp=1;
            for(auto k:j){
                temp_dp+=k;
                if(temp_dp<1){
                    min_dp+=(1-temp_dp);
                    temp_dp=1;
                }
                cout<<k;
            }
            t.push_back(min_dp);
            cout<<endl;
        }
        sort(t.begin(),t.end());
        cout<<t[0]<<endl;
    }
    return 0;
}
