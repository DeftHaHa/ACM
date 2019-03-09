#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LC p<<1,l,mid
#define RC p<<1|1,mid+1,r
#define lson p<<1
#define rson p<<1|1
long long s[400005];
long long lazy[400005];
bool clr[400005];
void pushdown(int p,int l,int r)
{
	
	if(clr[p])
	{
		lazy[lson] = lazy[rson] = s[lson] = s[rson] = 0; 
		clr[lson] = clr[rson] = true;
		clr[p] = false;
		//lazy[p] = 0;
	}
	if(lazy[p])
	{
		int mid = (l+r)/2;
		s[lson] += lazy[p]*(mid-l+1);
		s[rson] += lazy[p]*(r-mid);
		lazy[lson] += lazy[p];
		lazy[rson] += lazy[p];
		lazy[p] = 0;
	}
}
void pushup(int p)
{
	s[p] = s[lson] + s[rson];
}
void modify(int p,int l,int r,int L,int R,long long num)
{
	if(L<=l&&r<=R)
	{
		s[p] += (long long)(r-l+1) * num;
		lazy[p] += num;
		return;
	}
	pushdown(p,l,r);
	int mid = (l+r)/2;
	if(L<=mid) modify(LC,L,R,num);
	if(R>mid) modify(RC,L,R,num);
	pushup(p);
}
int TAG = 0;
void query(int p,int l,int r,long long k)
{
	if(l==r)
	{
		s[p] -= k;
		TAG = l;
		return;
	}
	int mid = (l+r)/2;
	pushdown(p,l,r);
	if(s[lson]>=k)
	{
		query(LC,k);
	}
	else
	{
		query(RC,k - s[lson]);	
		clr[lson] = true;
		s[lson] = lazy[lson] = 0;
	}
	pushup(p);
}
int main()
{

	int T,n,q;
	int o,l,r;
	long long k,x;
	cin>>T;
	while(T--)
	{
		
		scanf("%d%d",&n,&q);
		memset(lazy,0,sizeof(lazy));
		memset(clr,false,sizeof(clr));
		memset(s,0,sizeof(s));
		while(q--)
		{
			//cout<<"==="<<s[1]<<endl;
			scanf("%d",&o);
			if(o==1)
			{
				scanf("%d%d%lld",&l,&r,&x);
				modify(1,1,n,l,r,x);
			}
			else if(o==2)
			{
				scanf("%lld",&k);
				if(s[1]<k) cout<<"Trote_w is sb"<<endl;
				else
				{
					query(1,1,n,k);
					cout<<TAG<<endl;
				}
			}
		}
	}
	return 0;
}
