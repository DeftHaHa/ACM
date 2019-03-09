#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int N,l1,r1,l2,r2;
	cin>>N>>l1>>r1>>l2>>r2;
	int a[10005];
	for(int i = 0;i < N;i++) cin>>a[i];
	sort(a+l1-1,a+r1);
	sort(a+l2-1,a+r2,cmp);
	cout<<a[0];
	for(int i = 1;i < N;i++) cout<<' '<<a[i];
	cout<<endl;
	return 0;
}
