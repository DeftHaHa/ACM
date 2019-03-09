#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int T;
	cin>>T;
	double a;
	int b,c;
	double ee=exp(1);
	while(T--)
	{
		scanf("%lf%d%d",&a,&b,&c);
		double ans=pow(a,ee)/double(b);
		if(c==1) printf("%.1lf\n",ans);
		else if(c==2) printf("%.2lf\n",ans);
		else if(c==3) printf("%.3lf\n",ans);
		else if(c==4) printf("%.4lf\n",ans);
		else if(c==5) printf("%.5lf\n",ans);
	}
	return 0;
}
