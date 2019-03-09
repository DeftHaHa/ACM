#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
double ans[5000005];
int main()
{
	int T;
	cin>>T;
	ans[0] = 0;
	for(int i = 1;i < 5000000;i++){
		ans[i] = ans[i-1]+ 1/(double)i;
	}
	int n;
	while(T--)
	{
		cin>>n;
		printf("%.7lf\n",ans[n]);
	}
	return 0;
}
