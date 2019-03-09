#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int res=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
	return res;
}
int main()
{
	int a,b,x,y;
	cin>>a>>b;
	exgcd(a,b,x,y);
	if(b<0) b=-b;
	x%=b;
	if(x<0) x+=b;
	cout<<x<<endl;
	return 0;
}
