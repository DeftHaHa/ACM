#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int res(int n,int m)
{
	if(m&1) return n*((m+1)/2)-n/2;
	else return n*(m/2);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	cout<<max(res(n,m),res(m,n))<<endl;
	return 0;
}
