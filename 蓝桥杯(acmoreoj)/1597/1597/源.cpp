#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n;
int M[105][105];
int sum=0,ans1=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[105][105];
void dfs(int x,int y,int nowsum,int tot)
{
	if(nowsum==sum) {ans1=min(ans1,tot);return;}
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(!vis[tx][ty]&&tx>0&&tx<=n&&ty>0&&ty<=m&&nowsum+M[tx][ty]<=sum&&tot<ans1)
			dfs(tx,ty,nowsum+M[tx][ty],tot+1);
	}
	vis[x][y]=false;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&M[i][j]);
			sum+=M[i][j];
		}
	}
	if(sum%2==0)
	{
		memset(vis,false,sizeof(vis));
		ans1=0x3f3f3f3f;
		sum/=2;
		dfs(1,1,M[1][1],1);
	}
	else ans1=0;
	cout<<ans1<<endl;
	return 0;
}