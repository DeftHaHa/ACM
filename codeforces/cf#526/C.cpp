#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
const long long mod = 1e9+7;
int main()
{
	string s;
	cin>>s;
	int len = s.length();
	long long ans = 0,temp = 0;
	for(int i = 0;i < len;i++)
	{
		if(s[i]=='a')
		{
			ans = (ans+temp+1)%mod;
		}
		else if(s[i]=='b')
		{
			temp = ans;
		}
	}
	cout<<ans<<endl;
}
