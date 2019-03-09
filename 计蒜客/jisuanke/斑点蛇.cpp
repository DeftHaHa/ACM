#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int s[200005];
void modify1(int p,int x,int l,int r,int num)
{
	s[p]+=num;
	if(l==r) return;
	int mid=(r+l)>>1;
	if(x<=mid) modify1(p*2,x,l,mid,num);
	else modify1(p*2+1,x,mid+1,r,num);
}
int query(int p,int x,int y,int l,int r)
{
	if(x<=l&&r<=y) return s[p];
	int mid=(r+l)>>1;
	int res=0;
	if(x<=mid) res+=query(p*2,x,y,l,mid);
	if(y>mid) res+=query(p*2+1,x,y,mid+1,r);
	return res;
}
int main()
{
	string S;
	memset(s,0,sizeof(s));
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		modify1(1,i,1,n,m);
	}
	int x,y;
	while(1)
	{
		cin>>S;
		if(S[0]=='E') break;
		scanf("%d%d",&x,&y);
		if(S[0]=='Q') printf("%d\n",query(1,x,y,1,n));
		else if(S[0]=='A') modify1(1,x,1,n,y);
		else if(S[0]=='S') modify1(1,x,1,n,-y);
	}
	return 0;
}
