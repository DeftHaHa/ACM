#include<iostream>
using namespace std;
int n,a,b,mod;
int f(int n)
{
	if(n==1||n==2) return 1;
	return (a*f(n-1)+b*f(n-2))%mod;
}
int main()
{
	cin>>n>>a>>b>>mod;
	cout<<f(n);
	return 0;
}
