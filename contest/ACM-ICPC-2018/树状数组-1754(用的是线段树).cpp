#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int M[800005],scor[200005];
void build(int p,int l,int r)
{
	if(l==r)
	{
		M[p]=scor[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	M[p]=max(M[p<<1],M[p<<1|1]);
}
void modify(int p,int l,int r,int pos,int num)
{
	if(l==r)
	{
		M[p]=num;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) modify(p<<1,l,mid,pos,num);
	else modify(p<<1|1,mid+1,r,pos,num);
	M[p]=max(M[p<<1],M[p<<1|1]);
}
int query(int p,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return M[p];
	int mid=(l+r)>>1;
	int res=0;
	if(x<=mid) res=max(res,query(p<<1,l,mid,x,y));
	if(y>mid) res=max(res,query(p<<1|1,mid+1,r,x,y));
	return res; 
}
int main()
{
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++) scanf("%d",&scor[i]);
	build(1,1,N);
	char ch=getchar();
	int x,y;
	while(M--)
	{
		scanf("%c %d %d",&ch,&x,&y);
		char c=getchar();
		if(ch=='U') modify(1,1,N,x,y);
		else printf("%d\n",query(1,1,N,x,y));
	}
}
