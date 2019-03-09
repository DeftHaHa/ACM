#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double r[5];
int d[5]={0,1,2,3,5};
int n;
double ans;
void dfs(int y,double sum)
{  // cout<<sum<<endl;
	if(y>n) return;
	else if(y==n)
	{
		ans=max(ans,sum);
	}
	for(int i=1;i<=4;i++)
	{
		dfs(y+d[i],sum*pow(1.0+r[i],d[i]));
	}
}
int main()
{
	
	while(cin>>n)
	{
		for(int i=1;i<=4;i++) scanf("%lf",&r[i]);
		ans=1;
		dfs(0,1.0);
		printf("%.5lf\n",ans);
	}
	return 0;
}
