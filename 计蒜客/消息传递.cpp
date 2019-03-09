#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Next[200005];
int ans=0x3f3f3f3f;
int n;
void dfs(int now,int step,int fa)
{
	if(step>ans||step>n) return;
	else if(now==fa)
	{
		ans=min(ans,step);
		return;
	}
	dfs(Next[now],step+1,fa);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&Next[i]);
	for(int i=1;i<=n;i++)
	{
		dfs(Next[i],1,i);
	}
	cout<<ans<<endl;
	return 0;
}

