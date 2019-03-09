#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int w[400005],lazy[400005];
void pushdown(int p,int l,int r)
{
	if(lazy[p])
	{
		int mid=(r+l)>>1;
		w[p<<1]=lazy[p]*(mid-l+1);
		w[p<<1|1]=lazy[p]*(r-mid);
		lazy[p<<1]=lazy[p<<1|1]=lazy[p];
		lazy[p]=0;
	}
}
void modify1(int p,int x,int l,int r,int num)
{
	if(l==r)
	{
		w[p]=num;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) modify1(p<<1,x,l,mid,num);
	else modify1(p<<1|1,x,mid+1,r,num);
	w[p]=w[p<<1]+w[p<<1|1];
}
void modify(int p,int x,int y,int l,int r,int num)
{
	if(x<=l&&r<=y)
	{
		w[p]=(r-l+1)*num;
		lazy[p]=num;
		return;
	}
	pushdown(p,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) modify(p<<1,x,y,l,mid,num);
	if(y>mid) modify(p<<1|1,x,y,mid+1,r,num);
	w[p]=w[p<<1]+w[p<<1|1];
}
int main()
{
	int N,Q;
	cin>>N>>Q;
	int x,y,z;    
	memset(lazy,0,sizeof(lazy));
	memset(w,0,sizeof(w));
	for(int i=1;i<=N;i++) modify1(1,i,1,N,1);
	while(Q--)
	{
		scanf("%d%d%d",&x,&y,&z);
		modify(1,x,y,1,N,z);
	}
	printf("The total value of the hook is %d.\n",w[1]);
	return 0;
}
