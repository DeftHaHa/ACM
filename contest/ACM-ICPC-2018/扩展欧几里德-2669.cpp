#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
	while(~scanf("%d%d",&a,&b))
	{
		int gcd=exgcd(a,b,x,y);
		if(gcd==1)
		{
			int tb=b;
			if(b<0) tb=-b;
			int tx=(x%tb+tb)%tb;
			y=y-a*((tx-x)/b);
			printf("%d %d\n",tx,y);
		}
		else cout<<"sorry"<<endl;
	}
	return 0;
}
