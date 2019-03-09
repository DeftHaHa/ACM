#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const double eps=1e-8;
int main()
{
	double a,b,c,d,m,n;
	double N;
	scanf("%lf%lf%lf",&m,&n,&N);
	a=d=N;
	b=c=N+1;
	double ans1=(m*d-b*n)/(a*d-b*c);
	double ans2=(m*c-a*n)/(b*c-a*d);
	if(ans1>=0&&ans2>=0&&ans1-(int)ans1<eps&&ans2-(int)ans2<eps) printf("Yes\n");
	else printf("No\n");
	return 0;
}