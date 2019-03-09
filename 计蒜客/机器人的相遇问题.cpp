#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	long long res=exgcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-a/b*y;
	return res;
}
int main()
{
	long long X,Y,m,n,L;
	cin>>X>>Y>>m>>n>>L;
	long long A=n-m,B=L;
	long long C=X-Y;
	long long x,y;
	long long gcd=exgcd(A,B,x,y);
	if(C%gcd)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	B/=gcd;
	x*=C/gcd;
	x%=B;
	if(x<=0)x+=B;
	cout<<x<<endl; 
	return 0;
}
