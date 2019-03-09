#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int num[10],cnt;
int ans=0;
void dfsl(int l,int r,int H)  //l->r
{
	if(l>=r) return;
	int tag,maxh=0;
	for(int i=l;i<=r;i++)
	{
		if(num[i]>maxh)
		{
			tag=i;
			maxh=num[i];
		}
	}
	if(maxh==0) return;
	for(int i=tag+1;i<=r;i++)
	{
		ans+=maxh-num[i];
	}
	dfsl(l,tag-1,maxh);
}
void dfsr(int l,int r,int H) //r-->l
{
	if(l>=r) return;
	int tag,maxh=0;
	for(int i=r;i>=l;i--)
	{
		if(num[i]>maxh)
		{
			tag=i;
			maxh=num[i];
		}
	}
	if(maxh==0) return;
	for(int i=tag-1;i>=l;i--)
	{
		ans+=maxh-num[i];
	}
	dfsr(tag+1,r,maxh);
}
int main()
{
	for(int i=10000;i<1e6;i++)
	{
		int temp=i;int tp=ans;memset(num,0,sizeof(num));
		cnt=0;
		while(temp)
		{
			num[cnt++]=temp%10;
			temp/=10;
		}
		int H=0,tag;
		for(int j=0;j<cnt;j++)
		{
			if(num[j]>H)
			{
				H=num[j];
				tag=j;
			}
		}
		dfsl(0,tag-1,H);
		dfsr(tag+1,cnt-1,H);
	}
	cout<<ans<<endl;
	return 0;
}
