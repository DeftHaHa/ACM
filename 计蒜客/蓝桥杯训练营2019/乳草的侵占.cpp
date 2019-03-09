#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int X,Y,sx,sy;
char Map[105][105];
int vis[105][105];
int tot = 0;
int dx[8] = {0,0,-1,1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,-1,1,-1,1};
struct Node{
	int x,y,step;
};
queue<Node> q;
int bfs(int sx,int sy)
{
	while(!q.empty()) q.pop();
	q.push(Node{sx,sy,0});
	Map[sx][sy] = 'M';
	int cnt = 1;
	while(!q.empty()){
		Node now = q.front();
		q.pop();
//		printf("======\n");	cout<<cnt<<' '<<tot<<endl;
//			for(int i = 1;i <= X;i++){
//				for(int j = 1;j <= Y;j++){
//					printf("%2d",vis[i][j]);
//				}
//				cout<<endl;
//			}
		for(int i = 0;i < 8;i++){
			int tx = now.x + dx[i];
			int ty = now.y + dy[i];
			if(Map[tx][ty]=='.'){
				Map[tx][ty] = 'M';vis[tx][ty] = now.step+1;
				cnt++;
				if(cnt==tot) return now.step+1;
				q.push(Node{tx,ty,now.step+1});
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d%d%d",&Y,&X,&sy,&sx);
	memset(Map,'*',sizeof(Map));
	getchar();
	sx = X-sx+1;
	for(int i = 1;i <= X;i++){
		for(int j = 1;j <= Y;j++){
			scanf("%c",&Map[i][j]);
			if(Map[i][j] == '.') tot++;
		}
		getchar();
	}
	printf("%d\n",bfs(sx,sy));
	
	return 0;
}


