#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue> 
using namespace std;
int main()
{
	int T;
	cin>>T;
	double S,d,v1,v2;
	while(T--)
	{
		scanf("%lf%lf%lf%lf",&S,&d,&v1,&v2);
		double t = 0;
		if(d==S) t = 1.0;
		else if(v2 <= v1 || v2 > d){
			if(d<=S) t = 1.0 + (S-d)/v1;
			else t = S/v1;
		}
		else
		{
			double temp = (d-v2)/(v2 - v1) + 1.0;
			double mt = (double)((int)(S / temp / v2));
			if(S - temp * mt *v2 >= d) t = min(mt*temp + 1.0 + (S - mt*temp*v2 - d)/v1,mt*temp + (S - mt*temp*v2)/v1); 
			else t = mt*temp + (S - mt*temp*v2)/v1; 
		}
		printf("%.2lf\n",min(S/v1,t));
	}
	return 0;
} 
