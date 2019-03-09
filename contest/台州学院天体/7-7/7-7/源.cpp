#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct peo
{
	string name;
	int tot;
	double ave;
}p[1005];
bool cmp(const struct peo& a,const struct peo& b)
{
	if(a.tot==b.tot) return a.ave<b.ave;
	else return a.tot>b.tot;
}
int main()
{
	int N;
	int vis[205];
	while(cin>>N)
	{
		int n,id;
		for(int i=0;i<N;i++)
		{
			cin>>p[i].name;
			cin>>n;
			memset(vis,0,sizeof(vis));
			p[i].tot=0;
			int temp=n;
			while(n--)
			{
				cin>>id;
				if(!vis[id])
				{
					vis[id]++;
					p[i].tot++;
				}
			}
			if(temp>0) p[i].ave=(double)temp/(double)p[i].tot;
			else p[i].ave=0;
		}
		sort(p,p+N,cmp);
		if(N>0) 
		{
			cout<<p[0].name;
			for(int i=1;i<min(N,3);i++) cout<<' '<<p[i].name;
			for(int i=0;i<3-N;i++) cout<<" -";
		}
		else cout<<"- - -";
		cout<<endl;
	}
	return 0;
}