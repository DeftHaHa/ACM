#include<string>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double f1,f2,a;
	scanf("%lf%lf%lf",&f1,&f2,&a);
	double ans = sqrt(f1*f1+f2*f2+2*f1*f2*cos(a*3.14159265358979323/180.0));
	printf("%.10lf\n",ans);
	return 0;
}
