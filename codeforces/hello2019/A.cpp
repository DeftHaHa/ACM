#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	string s[6];
	for(int i = 0;i < 6;i++) cin>>s[i];
	bool flag = false;
	for(int i = 1 ;i < 6;i++){
		if(s[0][0] == s[i][0]||s[0][1]==s[i][1])flag = true;
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
