#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n;
int path[15];
bool vis[15];
void dfs(int cnt,int num){
	path[cnt] = num;
	if(cnt == n){
		for(int i = 1;i <= n;i++) printf("%d",path[i]);
		printf("\n");
		return;
	}
	vis[num] = true;
	for(int i = 1;i <= n;i++){
		if(!vis[i]) dfs(cnt+1,i);
	}
	vis[num] = false;
}
int main()
{
	scanf("%d",&n);
	int m = 1;
	for(int i = 2;i <= n;i++) m*=i;
	printf("%d\n",m);
	memset(vis,false,sizeof(vis));
	dfs(0,0);  
	return 0;
}
