#inlcude<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char maze[55][55];
int ans;
int T,N;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y)  //ÏàÁ¬Çø¿émin(even,odd) 
{
	
}
int main()
{
	
	cin>>T;
	while(T--)
	{
		memset(maze,'.',sizeof(maze));
		cin>>N;
		char ch=getchar();
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
				scanf("%c",&maze[i][j]);
			ch=getchar();
		}
		ans=0;
	}
	
	
	return 0;
}
 
