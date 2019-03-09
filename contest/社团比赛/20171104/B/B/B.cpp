#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n[100005];
int bsearch(int x,int M)
{
	int l=0,r=M;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(n[mid]==x) return mid;
		else if(n[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return -1;
}
int main()
{
	int T;

	cin>>T;
	while(T--)
	{
		int N,q;
		cin>>N>>q;
		for(int i=0;i<N;i++)
			scanf("%lld",&n[i]);
		while(q--)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",bsearch(x,N));
		}
	}
	return 0;
}