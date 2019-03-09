#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int ans = 0;
	for(int i = 0;i < s.length();i++)
	{
		if(s[i]=='A') ans++;
	}
	cout<<ans<<endl;
	return 0;
}
