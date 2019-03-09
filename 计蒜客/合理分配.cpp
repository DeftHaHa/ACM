#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct interval
{
	int l,r;
}itv[25];
bool cmp(const interval &a,const interval &b)
{
	if(a.l==b.l) return a.r<b.r;
	else return a.l<b.l;
}
int main()
{
	freopen("DATA.txt","r",stdin);
	for(int i=0;i<20;i++) scanf("%d%d",&itv[i].l,&itv[i].r);
	sort(itv,itv+20,cmp);
	interval temp[20];
	int cnt,ans=0;
	for(int j=1;j< 1<<20;j++)
	{
		cnt=0;
		bool flag=true;
		for(int i=0;i<20;i++)
		{
			if(j>>i&1)
			{
				temp[++cnt].r=itv[i].r;
				temp[cnt].l=itv[i].l;
				if(cnt>1)
				{
					if(itv[i].l<temp[cnt-1].r)
					{
						flag=false;
						break;
					}
				}
			}
		}
		if(cnt>ans&&flag)
		{
			ans=cnt;
			for(int k=1;k<=cnt;k++) printf("%d-%d   ",temp[k].l,temp[k].r);cout<<endl;
		}
	}
	cout<<ans<<endl;
}
