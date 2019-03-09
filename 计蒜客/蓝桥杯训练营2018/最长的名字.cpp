#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	string s,ans="";
	while(N--)
	{
		cin>>s;
		if(s.length()>ans.length()) ans = s;
		
	}
	cout<<ans<<endl;
	return 0;
}
