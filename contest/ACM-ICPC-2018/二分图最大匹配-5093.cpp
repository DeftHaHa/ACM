#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
int n,m;
const int maxn=55,maxN=55*55;
char mp[maxN][maxN];
int rid[maxn][maxn],cid[maxn][maxn];
bool e[maxn][maxn];
int match[maxN];
int vis[maxN];
int maxrid,maxcid;
void init()
{
	memset(rid,0,sizeof(rid));
	memset(cid,0,sizeof(cid));
	memset(e,0,sizeof(e));
	memset(match,-1,sizeof(match));
}
int makerow()
{
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		bool flag=false;
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='*')
			{
				rid[i][j]=cnt;
				flag=true;
			}
			else if(mp[i][j]=='#')
			{
				cnt++;
				flag=false;
			}
		}
		if(flag) ++cnt;
	}
	return cnt;
}
int makecolum()
{
	int cnt=1;
	for(int j=0;j<m;j++)
	{	
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			if(mp[i][j]=='*')
			{
				cid[i][j]=cnt;
				flag=true;
			}
			else if(mp[i][j]=='#')
			{
				cnt++;
				flag=false;
			}
		}
		if(flag) ++cnt;
	}
	return cnt;
}
void make_bmp()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='*')
			{
				e[rid[i][j]][cid[i][j]]=1;
			}
		}
	}
}

bool dfs(int u)
{
	for(int i=1;i<=maxcid;i++)
	{
		if(e[u][i]&&!vis[i])
		{
			vis[i]=true;
			if(match[i]==-1||dfs(match[i]))
			{
				match[i]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin>>T;
	while(T--)
	{
		init();
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",mp[i]);
		}
		maxrid=makerow();
		maxcid=makecolum();
		make_bmp();
		int ans=0;
		for(int i=1;i<=maxrid;i++)
		{
			memset(vis,false,sizeof(vis));
			if(dfs(i)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
