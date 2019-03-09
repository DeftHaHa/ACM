#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct answer
{
	string name;
	int tot;
};
vector<answer> ans;
bool cmp(const answer &a,const answer &b)
{
	return a.name<b.name;
}
vector<int> e[2005];
map<string,int> m;
int w[2005];
bool vis[2005];
int tot=0,head,wtot;
void dfs(int u)
{
	vis[u]=true;
	tot++;
	wtot+=w[u];
	if(w[u]>w[head]) head=u;
	for(unsigned int i=0;i<e[u].size();i++)
	{
		if(!vis[e[u][i]])
		{
			dfs(e[u][i]);
		}
	}
}
int main()
{
	int N,K;
	cin>>N>>K;
	string name1,name2;
	int time;
	int nid=0,u,v;
	memset(w,0,sizeof(w));
	while(N--)
	{
		cin>>name1>>name2>>time;
		if(!m.count(name1))
		{
			m[name1]=++nid;
			u=nid;
		}
		else u=m[name1];
		if(!m.count(name2)) 
		{
			m[name2]=++nid;
			v=nid;
		}
		else v=m[name2];
		w[u]+=time;
		w[v]+=time;                       
		e[u].push_back(v);
		e[v].push_back(u);
	}                 
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=nid;i++)
	{
		if(!vis[i])
		{
			tot=wtot=0;
			head=i;
			dfs(i);
			if(tot>2&&wtot/2>K)
			{
				answer temp;
				for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
				{
					if(it->second==head)
					{
						temp.name=it->first;
						break;
					}	
				}
				temp.tot=tot;
				ans.push_back(temp);
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans.size()<<endl;
	for(unsigned int i=0;i<ans.size();i++)
	{
		cout<<ans[i].name<<' '<<ans[i].tot<<endl;
	}
	return 0;
}