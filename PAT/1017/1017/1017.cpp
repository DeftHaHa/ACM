#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
struct people
{
	int T,P;
}p[10005];
bool cmp(const people &a,const people &b)
{
	return a.T<b.T;
}
int main()
{
	int N,K;
	int hh,mm,ss;
	while(cin>>N>>K)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d:%d:%d %d",&hh,&mm,&ss,&p[i].P);
			p[i].T=hh*3600+mm*60+ss;
			if(p[i].P>60) p[i].P=60;
		}
		sort(p,p+N,cmp);
		int tend[105];
		for(int i=0;i<=K;i++) tend[i]=28800;
		int tot=0,sum=0;
		for(int i=0;i<N;i++)
		{
			if(p[i].T<61201)
			{
				tot++;
				int mint=tend[0],tag=0;
				for(int j=0;j<K;j++)
				{
					if(tend[j]<mint)
					{
						tag=j;
						mint=tend[j];
					}
				}
				if(p[i].T<tend[tag])
				{
					sum+=tend[tag]-p[i].T;
					tend[tag]+=p[i].P*60;
				}
				else tend[tag]=p[i].T+p[i].P*60;
			}
		}
		if(tot==0) cout<<"0.0"<<endl;
		else printf("%.1f\n",sum/60.0/tot);
	}
	return 0;
}