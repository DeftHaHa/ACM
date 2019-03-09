#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const double inf=99999999;
struct station
{
	double p,d;
}s[505];
bool cmp(const station &a,const station &b)
{
	return a.d<b.d;
}
int main()
{  
	double cmax,D,w;
	bool arr=true;
	int N;
	cin>>cmax>>D>>w>>N;
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&s[i].p,&s[i].d);
	sort(s,s+N,cmp);
	if(s[0].d>0)
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	double cnow=0,maxd=cmax*w,ans=0;
	int nows=0;
	while(1)
	{
		int nexts;
		bool find=false;
		for(int i=nows+1;i<N;i++)
		{
			if(s[i].d>s[nows].d+maxd||s[i].d>=D) break;
			else if(s[i].p<=s[nows].p)
			{
				find=true;
				nexts=i;
				break;
			}
		}
		if(find)
		{
			ans+=((s[nexts].d-s[nows].d)/w-cnow)*s[nows].p;
			cnow=0;
		}
		else if(!find)
		{
			double minp=inf;
			for(int i=nows+1;i<N;i++)
			{
				if(s[i].d>s[nows].d+maxd||s[i].d>=D) break;
				if(s[i].p<=minp)
				{
					nexts=i;
					minp=s[i].p;
				}
			}
			if(s[nows].d+maxd>=D)
			{
				ans+=(D-s[nows].d)/w*s[nows].p;
				break;
			}
			else if(minp==inf)
			{
				printf("The maximum travel distance = %.2f\n",s[nows].d+maxd);
				arr=false;
				break;
			}
			ans+=(cmax-cnow)*s[nows].p;
			cnow=cmax-(s[nexts].d-s[nows].d)/w;
		}
		nows=nexts;
	}
	if(arr) printf("%.2f\n",ans);
	return 0;
}