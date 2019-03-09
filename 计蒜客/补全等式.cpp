#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n[13];
int ans=0,sum=0;
bool vis[14];
void dfs(int cnt,int num)
{
	n[cnt]=num;
	if(cnt==6)
	{
		if(n[1]*n[2]+n[3]*n[4]!=n[5]*n[6]) return;
	}
	else if(cnt==12)
	{
		if(n[7]*n[8]-n[9]*n[10]==n[11]*n[12])
		{
			//for(int i=1;i<13;i++) printf("%d ",n[i]);cout<<endl;
			ans++;
		}
		return;
	}
	vis[num]=true;
	for(int i=1;i<=13;i++)
	{
		if(!vis[i])
		{
			dfs(cnt+1,i);
		}
	}
	vis[num]=false;
};
int main()
{
	memset(vis,false,sizeof(vis));
	dfs(0,0);
	printf("%d",ans);
	return 0;
}
