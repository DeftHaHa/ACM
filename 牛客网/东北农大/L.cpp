#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sum[4000005];
char s[1000005][10];
int x[1000005],com[1000005];
void modify(int p,int l,int r,int x,int num)
{
	if(l==r)
	{
		sum[p]+=num;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) modify(p<<1,l,mid,x,num);
	else modify(p<<1|1,mid+1,r,x,num);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
int query(int p,int l,int r,int k)
{
	if(l==r)
	{
		return l;
	}
	int mid=(l+r)>>1;
	if(sum[p<<1|1]>=k) return query(p<<1|1,mid+1,r,k);
	else return query(p<<1,l,mid,k-sum[p<<1|1]);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(sum,0,sizeof(sum));
		int N,M;
		scanf("%d%d",&N,&M);
		x[0]=0;
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&com[i]);
			x[i]=com[i];
		}
		for(int i=1;i<=M;i++)
		{
			scanf("%s%d",s[i],&com[i+N]);
			x[i+N]=com[i+N];
		}
		sort(x,x+N+M+1);
		int tot=1;
		for(int i=2;i<=N+M;i++)
		{
			if(x[i]!=x[tot]) x[++tot]=x[i];
		}
		for(int i=1;i<=N;i++)
		{
			int pos=lower_bound(x,x+tot,com[i])-x;
			modify(1,1,tot,pos,1);
		}
		for(int i=1;i<=M;i++)
		{
			
			if(s[i][0]=='q')
			{
				printf("%d\n",x[query(1,1,tot,com[i+N])]);
			}	
			else if(s[i][0]=='i')
			{
				int pos=lower_bound(x,x+tot,com[i+N])-x;
				modify(1,1,tot,pos,1);
			}
			else
			{
				int pos=lower_bound(x,x+tot,com[i+N])-x;
				modify(1,1,tot,pos,-1);
			}
		}
	}
	return 0;
}
/*
1
5 8
6 4 2 9 1
query 2
insert 7
delete 6
query 2
query 1
query 3
query 4
query 5
*/
