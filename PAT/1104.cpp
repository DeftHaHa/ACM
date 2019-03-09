#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
double a;
int main()
{
	int N;
	scanf("%d",&N);
	double ans = 0;
	for(int i = 1;i <= N;i++){
		scanf("%lf",&a);	
		ans += a*(double)((ll)(i-1)*(N-i+1)+(N-i+1));
	}
	printf("%.2lf\n",ans);
	
	return 0;
}
