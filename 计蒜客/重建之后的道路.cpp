#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
bool mp[105][105];
int d[105];
int n,m;
struct cmp
{
	bool operator()(const int &a,const int &b) const
	{
		return d[a]>d[b];
	}
};
priority_queue<int,vector<int>,cmp> q;
void djkstra1(int s)
{
	d[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(mp[u][i])
			{
				if(d[u]+1<d[i])
				{
					q.push(i);
					d[i]=d[u]+1;
				}
			}
		}
	}
}
void djkstra2(int s)
{
	d[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(!mp[u][i])
			{
				if(d[u]+1<d[i])
				{
					q.push(i);
					d[i]=d[u]+1;
				}
			}
		}
	}
}
int main()
{	
	int u,v;
	cin>>n>>m;
	memset(mp,0,sizeof(mp));
	while(m--)
	{
		scanf("%d%d",&u,&v);
		mp[u][v]=true;
		mp[v][u]=true;
	}
	memset(d,0x3f,sizeof(d));
	djkstra1(1);
	int train=d[n];
	memset(d,0x3f,sizeof(d));
	djkstra2(1);
	int road=d[n];
	cout<<max(road,train)<<endl;
	return 0;
}
