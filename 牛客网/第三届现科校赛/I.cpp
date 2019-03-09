#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct SL
{
	int l,r,v;
}sl[10005];
bool cmp1(SL a,SL b)
{
	if(a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}
struct cmp2
{
	bool operator()(SL a,SL b)const
	{
		return a.r>b.r;
	}	
};
priority_queue<SL,vector<SL>,cmp2> q;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		while(!q.empty()) q.pop();
		for(int i = 0;i < m;i++) scanf("%d%d%d",&sl[i].l,&sl[i].r,&sl[i].v);
		sort(sl,sl+m,cmp1);
		int pos = 0,ans = 0;
		for(int i = 1;i <= n;i++)
		{
			while(!q.empty()&&q.top().r<i) q.pop(); //cout<<"###"<<sl[pos].l<<' '<<sl[pos].r<<endl;
			while(pos < m && sl[pos].l == i)
			{
				q.push(SL{sl[pos].l,sl[pos].r,sl[pos].v});
				pos++;
			}
			if(!q.empty())
			{
				ans++;
				SL now = q.top();
				q.pop();
				now.v--;
				if(now.v) q.push(now);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
