#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double ans=0;
	for(int i=1;i<=100;i++)
	{
		if(i&1) ans+=1.0/(double)i;
		else ans-=1.0/(double)i;
	}
	printf("%6lf",ans);
	return 0;
}
