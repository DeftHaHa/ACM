#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
struct edgde
{
	int v,next,w;
}e[10005];
int p[10005];
int eid;
void addedge(int u,int v,int w)
{
	e[eid].v=v;
	e[eid].w=w;
	e[eid].next=p[u];
	p[u]=eid++;
}
int d[505];
int cmax,sp,N,M;
int s[505];
bool vis[505];
int path[505];
int tot;
vector<int> r[505];
void djkstra()
{
	memset(d,0x3f,sizeof(d));
	memset(vis,false,sizeof(vis));
	d[0]=0;
	tot=0;
	for(int i=0;i<=N;i++)
	{
		int mind=inf,v=0,j;
		for(j=0;j<N;j++)
		{
			if(!vis[j] && d[j]<mind )
			{
				mind=d[j];
				v=j;
			}
		}
		if(mind==inf) return;
		vis[v]=true;
		for(j=p[v];j!=-1;j=e[j].next)
		{
			int x=e[j].v;
			int dnew=d[v]+e[j].w;
			if(!vis[x]&&dnew<=d[x])
			{
				if(x==sp)
				{
					if(dnew<d[sp])
					{
						d[x]=dnew;
						path[x]=v;
						for(int k=0;k<tot;k++) r[k].clear();
						tot=0;
						int temp=x;
						while(temp!=0)
						{
							r[tot].push_back(temp);
							temp=path[temp];
						};
						tot++;
					}
					else if(dnew==d[sp])
					{
						path[x]=v;
						int temp=x;
						r[tot].push_back(x);
						while(temp!=0)
						{
							temp=path[temp];
							r[tot].push_back(temp);
						};
						tot++;
					}
					continue;
				}
				d[x]=dnew;
				path[x]=v;
			}
		}
	}
}
int main()
{

	while(cin>>cmax>>N>>sp>>M)
	{
		for(int i=1;i<=N;i++)
			cin>>s[i];
		s[0]=cmax/2;
		memset(p,-1,sizeof(p));
		eid=0;
		int u,v,w;
		while(M--)
		{
			cin>>u>>v>>w;
			addedge(u,v,w);
			addedge(v,u,w);
		}
		djkstra();
		int mintake=inf,ans;
		int take=0,back=0,sum=0,t;
		int per=cmax/2;
		int ans2;
		for(int i=0;i<tot;i++)
		{
			take=0,back=0,sum=0,t=0;
			bool flag=true;
			for(vector<int>::reverse_iterator it=r[i].rbegin();it!=r[i].rend();it++)
			{
				if(flag&&s[*it]<per)
				{
				        if(back>=per-s[*it])
                                        {
                                                flag=false;
                                        }
					else
                                        {
                                                t+=per-s[*it]-back;
                                                back=0;
                                        }
				}
				if(!flag&&s[*it]<per)
				{
					take+=per-s[*it];
				}
				else if(s[*it]>per)
				{
					back+=s[*it]-per;
				}

			}
			if(back>take)
			{
				back-=take;
				take=0;
			}
			if(take+t<mintake)
                        {
                                mintake=take+t;
                                ans2=back;
                                ans=i;
                        }
		}
		cout<<mintake<<' ';
		cout<<0;
		for(vector<int>::reverse_iterator it=r[ans].rbegin();it!=r[ans].rend();it++)
		{
			if(*it!=0)
			cout<<"->"<<*it;
		}
		cout<<' '<<back<<endl;
	}
	return 0;
}
