#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int w,h;
	int u1,d1,u2,d2;
	cin>>w>>h;
	cin>>u1>>d1>>u2>>d2;
	int sum[105];
	sum[0] = 0;
	for(int i = 1;i <= 100;i++) sum[i] = sum[i-1]+i;
	if(d1<d2)
	{
		swap(d1,d2);
		swap(u1,u2);
	}
	int ans = w + sum[h]-sum[d1-1] - u1;
	if(ans<0) ans = 0;
	if(d2==0) d2=1;
	ans += sum[d1-1] - sum[d2-1] - u2;
	if(ans<0) ans = 0; 
	ans += sum[d2-1] - sum[0]; 
	cout<<ans<<endl;
	
	return 0;
} 
