#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
	int x,y,w;
}node[100005];
bool cmp1(const Node &a,const Node &b)
{
	return a.x<b.x;
}
bool cmp2(const Node &a,const Node &b)
{
	return a.y<b.y;
}
int Max(int a,int b,int c,int d)
{
	if(b>a) a=b;
	if(c>a) a=c;
	if(d>a) a=d;
	return a;
}
int dp[1000005][3];
int main()
{
	int T;
	int n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++) scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].w);
		sort(node,node+n,cmp1);
		sort(node,node+n,cmp2);
		for(int i=0;i<n;i++) printf("%d %d=>",node[i].x,node[i].y);
		int tag=0;
		for(int i=0;i<n;i++) if(node[i].x>0&&node[i].y>0) {tag=i;break;}
		int tx=0,ty=0;
		dp[tag-1][0]=dp[tag-1][1]=dp[tag-1][2]=0;
		int flag=0;
		for(int i=tag;i<n;i++)
		{
			if(node[i].x>tx&&node[i].y>ty)
			{
				int M=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
				dp[i][0]=M+node[i].w;
				dp[i][1]=dp[i][2]=M;
				flag=i;
				
			}
			else if(node[i].x<=tx||node[i].y<=ty) 
			{
				dp[i][1]=dp[i][2]=Max(dp[flag-1][0]+node[i].w,dp[flag][0],dp[i-1][1],dp[i-1][2]);
			}
			else
			{
				dp[i][1]=dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			}
			printf("%d %d %d %d\n",i,dp[i][0],dp[i][1],dp[i][2]);
			tx=node[i].x;
			ty=node[i].y;
		}
		cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
	}
	return 0;
} 
