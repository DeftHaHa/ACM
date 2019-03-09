#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int sex;
	double h,w;
	int ans=0;
	freopen("DATA.txt","r",stdin);
	for(int i=0;i<20;i++)
	{
		scanf("%d%lf%lf",&sex,&h,&w);
		double stan;
		if(sex==1) stan=(h-80)*0.7;
		else stan=(h-70)*0.6;
		if(stan*0.9<=w&&w<=stan*1.1)
		{
			cout<<sex<<' '<<h<<' '<<stan<<' '<<w<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
