#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int M[800005];
int h,w,n;
void query(int p,int l,int r,int num)
{
	if(l==r)
	{
		if(l<=h)
		{
			printf("%d\n",l);
			M[p]-=num;
		}
		else printf("-1\n");
		return;
	}
	int mid=(r+l)>>1;
	if(M[p*2]>=num) query(p<<1,l,mid,num);
	else if(M[p*2+1]>=num) query(p<<1|1,mid+1,r,num);
	else printf("-1\n");
	M[p]=max(M[p<<1],M[p<<1|1]);
}
int main()
{
	cin>>h>>w>>n;
	for(int i=1;i<=4*n;i++) M[i]=w;
	int l;
	int temp=n;
	while(temp--)
	{
		scanf("%d",&l);
		query(1,1,n,l);
	}
	return 0;
}
