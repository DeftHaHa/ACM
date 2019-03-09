#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	if(a%3 == b%3) return a<b;
	return a%3 < b%3;
}
int main()
{
	int N;
	int a[10005];
	cin>>N;
	for(int i = 0;i < N;i++) cin>>a[i];
	sort(a,a+N,cmp);
	cout<<a[0];
	for(int i = 1;i < N;i++) cout<<' '<<a[i];
	cout<<endl;
	return 0;
}
