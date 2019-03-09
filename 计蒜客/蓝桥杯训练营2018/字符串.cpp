#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i = 0;i < s.length();i++)
	{
		if(s[i]>='a'&&s[i]<'z'||s[i]>='A'&&s[i]<'Z') s[i]++;
		else if(s[i]=='z') s[i] = 'a';
		else if(s[i]=='Z') s[i] = 'A';
	}
	cout<<s<<endl;
	return 0;
}
