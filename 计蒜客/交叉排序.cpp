#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n[100005];
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	int N,l1,r1,l2,r2;
	scanf("%d%d%d%d%d",&N,&l1,&r1,&l2,&r2);
	for(int i=0;i<N;i++) scanf("%d",&n[i]);
	sort(n+l1-1,n+r1);
	sort(n+l2-1,n+r2,cmp);
	printf("%d",n[0]);
	for(int i=1;i<N;i++) printf(" %d",n[i]);
	printf("\n");
	return 0;
}
