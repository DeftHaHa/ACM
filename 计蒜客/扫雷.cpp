#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	char mat[105][105];
	cin>>n>>m;
	memset(mat,'.',sizeof(mat));
	char ch=getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%c",&mat[i][j]);
		ch=getchar();
	}
	char ans[105][105];
	int dx[]={0,0,1,-1,1,1,-1,-1};
	int dy[]={1,-1,0,0,1,-1,1,-1};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mat[i][j]=='.')
			{
				int cnt=0;
				for(int k=0;k<8;k++)
				{
					if(mat[i+dx[k]][j+dy[k]]=='*') cnt++;
				}
				ans[i][j]='0'+cnt;
			}
			else ans[i][j]='*';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
