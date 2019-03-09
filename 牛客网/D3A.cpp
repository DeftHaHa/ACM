#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI 3.141592654
#define E 2.71828182846
int l(int n,int s)
{
    int ans=1;
    if(n>0)
    {
		double a=log10(2*PI*n)/2+n*log10(n/E);
		ans=(int)(a/log10(s))+1;
	}
    return ans;
}
int main()
{
	int n;
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",l(n,8));
	}
	return 0;
}
