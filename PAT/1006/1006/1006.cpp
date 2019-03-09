#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
struct people
{
	string s;
	int ih,im,is;
	int oh,om,os;
}p[20];
bool cmp1(const people &a,const people &b)
{
	if(a.ih==b.ih)
	{
		if(a.im==b.im)
		{
			return a.is<b.is;
		}
		else return a.im<b.im;
	}
	else
	{
		return a.ih<b.ih;
	}
}
bool cmp2(const people &a,const people &b)
{
	if(a.oh==b.oh)
	{
		if(a.om==b.om)
		{
			return a.os>b.os;
		}
		else return a.om>b.om;
	}
	else
	{
		return a.oh>b.oh;
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>p[i].s;
			scanf("%d:%d:%d",&p[i].ih,&p[i].im,&p[i].is);
			scanf("%d:%d:%d",&p[i].oh,&p[i].om,&p[i].os);
		}
		sort(p,p+n,cmp1);
		cout<<p[0].s;
		sort(p,p+n,cmp2);
		cout<<' '<<p[0].s<<endl;
	}
	return 0;
}