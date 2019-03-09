#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100005;
long long a[maxn];
long long sum[maxn*4],lazy[maxn*4];
void build(int p,int l,int r)
{
	if(l==r)
	{
		sum[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
void pushdown(int p,int l,int r,int mid)
{
	if(lazy[p])
	{
		sum[p<<1]+=(mid-l+1)*lazy[p];
		sum[p<<1|1]+=(r-mid)*lazy[p];
		
		lazy[p<<1]+=lazy[p];
		lazy[p<<1|1]+=lazy[p];
		lazy[p]=0;
	}
}
void modify(int p,int l,int r,int x,int y,int num)
{
	if(x<=l&&r<=y)
	{
		sum[p]+=(r-l+1)*num;
		lazy[p]+=num;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(p,l,r,mid);
	if(x<=mid) modify(p<<1,l,mid,x,y,num);
	if(y>mid) modify(p<<1|1,mid+1,r,x,y,num);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
long long query(int p,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return sum[p];
	int mid=(l+r)>>1;
	pushdown(p,l,r,mid);
	long long res=0;
	if(x<=mid) res+=query(p<<1,l,mid,x,y);
	if(y>mid) res+=query(p<<1|1,mid+1,r,x,y);
	return res;
}
int main()
{
	int N,Q;
	while(~scanf("%d%d",&N,&Q))
	{
		for(int i=1;i<=N;i++) scanf("%lld",&a[i]);
		build(1,1,N);
		char c;
		int x,y,num;
		char ch=getchar();
		while(Q--)
		{
			scanf("%c",&c);
			if(c=='Q')
			{
				scanf("%d%d",&x,&y);
				ch=getchar();
				printf("%lld\n",query(1,1,N,x,y));
			}
			else
			{
				scanf("%d%d%d",&x,&y,&num);   
				ch=getchar();
				modify(1,1,N,x,y,num);
			}
		}
	}
}
