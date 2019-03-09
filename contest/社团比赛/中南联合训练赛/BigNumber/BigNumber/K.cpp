#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI 3.141592654
#define E 2.71828182846
int l(int n)
{
    int s=1;
    if(n>3)
        s=log10(2*PI*n)/2+n*log10(n/E)+1;
    return s;
}
int main()
{
	int n;
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",l(n));
	}
	return 0;
}