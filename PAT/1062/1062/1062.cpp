#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct peo
{
	char id[10];
	int v,t,tot;
}p[100005];
bool cmp(const peo &a,const peo &b)
{
	if(a.tot==b.tot)
	{
		if(a.v==b.v) return strcmp(a.id,b.id)<0;
		else return a.v>b.v;
	}
	else return a.tot>b.tot;
}
int main()
{
	int N,L,H;
	int ans=0;
	vector<peo> sage,nob,fool,small;
	cin>>N>>L>>H;
	for(int i=0;i<N;i++)
	{
		scanf("%s %d %d",&p[i].id,&p[i].v,&p[i].t);
		if(p[i].v>=L&&p[i].t>=L)
		{
			ans++;
			p[i].tot=p[i].v+p[i].t;
			if(p[i].v>=H)
			{
				if(p[i].t>=H) sage.push_back(p[i]);
				else nob.push_back(p[i]);
			}
			else
			{
				if(p[i].v>=p[i].t) fool.push_back(p[i]);
				else small.push_back(p[i]);
			}
		}
	}
	sort(sage.begin(),sage.end(),cmp);
	sort(nob.begin(),nob.end(),cmp);
	sort(fool.begin(),fool.end(),cmp);
	sort(small.begin(),small.end(),cmp);
	vector<peo>::iterator it;
	cout<<ans<<endl;
	for(it=sage.begin();it!=sage.end();it++) printf("%s %d %d\n",it->id,it->v,it->t);
	for(it=nob.begin();it!=nob.end();it++) printf("%s %d %d\n",it->id,it->v,it->t);
	for(it=fool.begin();it!=fool.end();it++) printf("%s %d %d\n",it->id,it->v,it->t);
	for(it=small.begin();it!=small.end();it++) printf("%s %d %d\n",it->id,it->v,it->t);
	return 0;
}