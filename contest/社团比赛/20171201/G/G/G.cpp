#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int x[12]={1,1,2,2,2,2,3,3,3,3,4,4};
int y[12]={2,3,1,2,3,4,1,2,3,4,2,3};
bool maze[10][10];
int minstep;
int anstot;
bool ans[10][10],vis[10][10];
void display()
{
	printf("  %d %d\n",ans[1][2],ans[1][3]);
	printf("%d %d %d %d\n",ans[2][1],ans[2][2],ans[2][3],ans[2][4]);
	printf("%d %d %d %d\n",ans[3][1],ans[3][2],ans[3][3],ans[3][4]);
	printf("  %d %d\n",ans[4][2],ans[4][3]);
}
bool finish()
{
	bool flag=maze[x[0]][y[0]];
	for(int i=1;i<12;i++)
	{
		if(maze[x[i]][y[i]]!=flag) return false;
	}
	return true;
}
void bfs(int j,int step)
{

	if(finish())
	{
		if(step<minstep)
		{ 
			for(int i=0;i<12;i++) ans[x[i]][y[i]]=vis[x[i]][y[i]];
			minstep=step;
			anstot=1;      //cout<<"=========="<<endl;cout<<step<<endl; display();//system("pause");
			return;
		}
		else if(step==minstep) {anstot++;return;}
	}
	for(int i=j+1;i<12;i++)
	{
		if(!vis[x[i]][y[i]]&&step<minstep)
		{
			vis[x[i]][y[i]]=true; 
			for(int t=1;t<=4;t++) maze[x[i]][t]=!maze[x[i]][t];
			for(int t=1;t<=4;t++) maze[t][y[i]]=!maze[t][y[i]];
			maze[x[i]][y[i]]=!maze[x[i]][y[i]];

			bfs(i,step+1);

			vis[x[i]][y[i]]=false; 
			for(int t=1;t<=4;t++) maze[x[i]][t]=!maze[x[i]][t];
			for(int t=1;t<=4;t++) maze[t][y[i]]=!maze[t][y[i]];
			maze[x[i]][y[i]]=!maze[x[i]][y[i]];
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(maze,false,sizeof(maze));
		for(int i=0;i<12;i++)	scanf("%d",&maze[x[i]][y[i]]);
		minstep=0x3f3f3f3f;
		memset(vis,false,sizeof(vis));
		anstot=0;
		bfs(-1,0);
		printf("%d\n",minstep);
		if(anstot>1) printf("123.cpp\n");
		else
		{
			printf("  %d %d\n",ans[1][2],ans[1][3]);
			printf("%d %d %d %d\n",ans[2][1],ans[2][2],ans[2][3],ans[2][4]);
			printf("%d %d %d %d\n",ans[3][1],ans[3][2],ans[3][3],ans[3][4]);
			printf("  %d %d\n",ans[4][2],ans[4][3]);
		}
	}
	return 0;
}