#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long s[400005],lazy[400005];
int a[100005];
void build(int p,int l,int r)
{
	if(l==r)
	{
		s[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	s[p]=s[p<<1]+s[p<<1|1];
}
void down(int p,int l,int r)
{
	if(lazy[p])
	{
		int mid=(l+r)>>1;
		s[p<<1]+=(mid-l+1)*lazy[p];
		s[p<<1|1]+=(r-mid)*lazy[p];
		lazy[p<<1]+=lazy[p];
		lazy[p<<1|1]+=lazy[p];
		lazy[p]=0;
	}
}
void modify(int p,int x,int y,int l,int r,int num)
{
	if(x<=l&&r<=y)
	{
		s[p]+=(r-l+1)*num;
		lazy[p]+=num;
		return;
	}
	down(p,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) modify(p<<1,x,y,l,mid,num);
	if(y>mid) modify(p<<1|1,x,y,mid+1,r,num);
	s[p]=s[p<<1]+s[p<<1|1];
}
long long query(int p,int x,int y,int l,int r)
{
	if(x<=l&&r<=y) return s[p];
	int mid=(l+r)>>1;
	down(p,l,r);
	long long ans=0;
	if(x<=mid) ans+=query(p<<1,x,y,l,mid);
	if(y>mid) ans+=query(p<<1|1,x,y,mid+1,r);
	return ans; 
}
int main()
{
	memset(lazy,0,sizeof(lazy));
	memset(s,0,sizeof(s));
	char c;
	int x,y;
	int N,Q,m;
	cin>>N>>Q;
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
	build(1,1,N);
	char ch=getchar();
	while(Q--)
	{
		scanf("%c",&c); // cout<<c<<endl;
		if(c=='Q')
		{
			scanf("%d%d",&x,&y);
			ch=getchar();
			printf("%lld\n",query(1,x,y,1,N));
		}
		else
		{
			scanf("%d%d%d",&x,&y,&m);
			ch=getchar();
			modify(1,x,y,1,N,m);
		}
	}
	return 0;
}
