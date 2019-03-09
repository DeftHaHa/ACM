#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	double r1,r2;
	while(scanf("%lf%lf",&r1,&r2)!=EOF)
	{
		if(r1==0&&r2==0) break;
		double D=sqrt((r1+r2)*(r1+r2)-(r1-r2)*(r1-r2));
		if(r1+r2+D<2.0*max(r1,r2))
			printf("%.2lf\n",2.0*max(r1,r2));
		else
			printf("%.2lf\n",r1+r2+D);
	}
	return 0;
}
