#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct NUM
{
	int n,score;
}a[105];
bool cmp(NUM a,NUM b){
	return a.score > b.score;
}
int main()
{
	int N;
	cin>>N;
	for(int i = 0;i < N;i++)
	{
		scanf("%d",&a[i].score);
		a[i].n = i+1;
	}
	sort(a,a+N,cmp);
	printf("%d",a[0].n);
	for(int i = 1 ; i < N;i++)
	{
		printf(" %d",a[i].n);
	}
	printf("\n");
	return 0;
}
