#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps = 1e-10;
int main()
{
	int t;
	scanf("%d",&t);
	double d;
	while(t--)
	{
		scanf("%lf",&d);
		if(d == 0) printf("Y %.12lf %.12lf\n",0.0,0.0);
		else if(d < 4.0) printf("N\n");
		else if(d == 4.0) printf("Y %.12lf %.12lf\n",2.0,2.0);
		else
		{
			double l = 1.0,r = d;
			for(int i = 0;i < 1000;i++)
			{
				double mid = (l+r)/2;
				double b = mid/(mid-1.0);
				if(mid*b > d) r = mid;
				else l = mid;
			}
			r = d - l;
			if(r>l) swap(l,r);
			printf("Y %.12lf %.12lf\n",l,r);
		}
	}
	return 0;
}
