#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	//double x = 500;
	//double t = x/5.0+sqrt(800*800 + (1000.0-x)*(1000.0-x))/2.0;
	//cout<<t<<endl;
	double ans,Min = 1000.0;
	for(double x = 0.0;x <= 1000.0;x+=0.00001)
	{
		double t = x/5.0+sqrt(800*800 + (1000.0-x)*(1000.0-x))/2.0;
		if(t < Min){
			Min = t;
			ans = x;
		}
	}
	printf("%.3lf %lf",Min ,ans);
	return 0;
}
