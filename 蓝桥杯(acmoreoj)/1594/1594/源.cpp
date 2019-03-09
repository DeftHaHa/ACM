#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	b=a*b/gcd(a,b);
	cout<<b*c/gcd(b,c)<<endl;
	return 0;
}