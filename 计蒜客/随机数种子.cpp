#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(gcd(n,m)==1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
