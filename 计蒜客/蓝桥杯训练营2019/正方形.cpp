#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n;
int len[25],aim;
bool flag = false;
bool vis[25];
void dfs(int cnt,int sum,int pos){
	if(cnt==4){
		flag=true;
		return;
	}
	if(flag) return;
	if(sum == aim){
		dfs(cnt+1,0,0);
		return;
	}
	else if(sum > aim) return;
	for(int i = pos+1;i <= n;i++){ //¼ôÖ¦  
		if(!vis[i]){
			vis[i] = true;
			dfs(cnt,sum + len[i],i);
			vis[i] = false;
		}
	}
}
int main()
{
	scanf("%d",&n);
	int sum = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&len[i]);
		sum += len[i];
	}
	if(sum%4){
		printf("No\n");
		return 0;
	}
	else aim = sum/4;
	memset(vis,false,sizeof(vis));
	dfs(0,0,0);
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}
