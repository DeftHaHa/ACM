#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int M[800005];
void modify(int p,int x,int l,int r,int num)
{
	if(l==r)
	{
		M[p]=num;
		return;
	}
	int mid=(r+l)>>1;
	if(x<=mid) modify(p*2,x,l,mid,num);
	else modify(p*2+1,x,mid+1,r,num);
	M[p]=max(M[p*2],M[p*2+1]);
}
int ans;
void query(int p,int x,int y,int l,int r)
{
	if(x<=l&&r<=y)
	{
		ans=max(M[p],ans);
		return;
	}
	int mid=(r+l)>>1;
	if(x<=mid) query(p*2,x,y,l,mid);
	if(y>mid) query(p*2+1,x,y,mid+1,r);
}
int main()
{
	int n,m;
	cin>>n>>m;
	memset(M,0,sizeof(M));
	int su;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&su);
		modify(1,i,1,n,su);
	}
	char c;
	int x,y;
	char ch=getchar();
	while(m--)
	{
		scanf("%c%d%d",&c,&x,&y);  
		ch=getchar();
		if(c=='Q')
		{
			ans=0;
			query(1,x,y,1,n);
			printf("%d\n",ans);
		}
		else modify(1,x,1,n,y);
	}
	return 0;	
} 
