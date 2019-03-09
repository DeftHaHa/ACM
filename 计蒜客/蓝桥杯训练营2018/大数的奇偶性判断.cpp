#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	if((s[s.length()-1]-'0')&1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
