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
	int n1=(a<<1)&((1<<k)-1);   //����K=3ʱ011�ɱ�Ϊ110��111 
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
		for(int i=1;i<k;i++) printf("0"); //��ͷһ����k��0�������k-1��0 
		memset(vis,false,sizeof(vis));
		tot=0;
		dfs(0);
		for(int i=tot;i>=k;i--) printf("%d",ans[i]);  //���k��0��ǰ��k���γɻ� 
		printf("\n");
	}
	return 0;
}
