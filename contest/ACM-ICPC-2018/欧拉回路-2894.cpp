#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=(1<<11)+5; 
bool vis[maxn];
int k;
int ans[maxn],tot;
void dfs(int a)
{
	int n1=(a<<1)&((1<<k)-1);   //比如K=3时011可变为110和111 
	int n2=n1+1;
	if(!vis[n1])
	{
		vis[n1]=true;
		dfs(n1);
		ans[++tot]=0;
	}
	if(!vis[n2])
	{
		vis[n2]=true;
		dfs(n2);
		ans[++tot]=1;
	}
}
int main()
{
	while(~scanf("%d",&k))
	{
		printf("%d ",1<<k);
		for(int i=1;i<k;i++) printf("0"); //开头一定是k个0，先输出k-1个0 
		memset(vis,false,sizeof(vis));
		tot=0;
		dfs(0);
		for(int i=tot;i>=k;i--) printf("%d",ans[i]);  //最后k个0与前面k个形成环 
		printf("\n");
	}
	return 0;
}
