#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	long long ans = 1,now = 1;
	for(int i = 2;i<=100;i++)
	{
		now += i;
		ans += now;
	}
	cout<<ans<<endl;
	return 0;
}
