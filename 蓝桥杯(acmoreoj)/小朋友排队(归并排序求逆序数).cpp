#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int h[1000005],tot[1000005];
void Mergesort(int l,int r)
{
	int mid=(l+r)/2;
	Mergesort(l,mid);
	Mergesort(mid+1,r);
	Merge(l,mid,r);
}
int t[1000005];
void Merge(int l,int mid,int r)
{
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(h[i]>h[j])
		{
			t[k++]=h[j++];
			tot
		}
		else t[k++]=h[i++];
	}
}
int main()
{
	int N;
	for(int i=0;i<N;i++) scanf("%d",&h[i]);
	memset(tot,0,sizeof(tot));
	Mergesort(0,N-1);
	return 0;
}
