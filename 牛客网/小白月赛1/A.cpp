#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
double quickpow(double a,int n)
{
	double res=1.0;
	while(n)
	{
		if(n&1) res*=a;
		a*=a;
		n>>=1;
	}
	return res;
}
int main()
{
	int a,b;
	int c;
	int T;
	double ee=exp(1);
	while(~scanf("%d",&T))
	{
		while(T--)
		{
			scanf("%d%d%d",&a,&b,&c);
			double ans=quickpow(ee,a)*(double)b;
			if(c==1) printf("%.1lf\n",ans);
			else if(c==2) printf("%.2lf\n",ans);
			else if(c==3) printf("%.3lf\n",ans);
			else if(c==4) printf("%.4lf\n",ans);
			else if(c==5) printf("%.5lf\n",ans);
		}
		
	}
}
