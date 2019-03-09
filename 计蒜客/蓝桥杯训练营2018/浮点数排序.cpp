#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-6;
bool cmp(double a,double b)
{
	if(abs(abs(a-round(a))-abs(b-round(b))) < eps) return a<b;
	else return abs(a-round(a)) < abs(b-round(b));
}
int main()
{
	int N;
	double a[105];
	cin>>N;
	for(int i = 0;i<N;i++)
	{
		scanf("%lf",&a[i]); 
	}
	sort(a,a+N,cmp);
	printf("%.6lf",a[0]);
	for(int i= 1;i<N;i++) printf(" %.6lf",a[i]);
	printf("\n");
	return 0;
}
