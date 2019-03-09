#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int a[105];
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i = 2;i <= n;i+=2)
	{
		ans += a[i]-a[i-1];
	}
	cout<<ans<<endl;
	return 0;
}
