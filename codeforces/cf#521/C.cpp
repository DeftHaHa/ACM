#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct A
{
	int v,id;
}a[1000005];
int ans[1000005],ansCnt = 0;
bool cmp(A a,A b)
{
	return a.v<b.v;
}
int main()
{
	int n;
	scanf("%d",&n);
	long long sum = 0;
	for(int i=0;i < n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].id = i+1;
		sum += (long long)a[i].v;
	}
	sort(a,a+n,cmp);
	sum -= a[n-1].v;
	for(int i = 0;i < n-1;i++)
	{
		if(sum-a[i].v == a[n-1].v)
		{	
			ans[ansCnt++] = a[i].id;
		}
	}
	if(sum-a[n-2].v == a[n-2].v) ans[ansCnt++] = a[n-1].id;
	//printf("%d %d %d\n",a[n-1],sum-a[n-2].v,a[n-2].v);
	printf("%d\n",ansCnt);
	for(int i = 0;i < ansCnt;i++)
	{
		printf("%d",ans[i]);
		if(i!=ansCnt-1) printf(" ");
	}
	printf("\n");
	return 0;
}
