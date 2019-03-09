#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long fib[50];
	fib[1]=fib[2]=1;
	for(int i=3;i<=46;i++) fib[i]=fib[i-1]+fib[i-2];
	int n;
	cin>>n;
	cout<<fib[n+1]<<endl;
	return 0;
}