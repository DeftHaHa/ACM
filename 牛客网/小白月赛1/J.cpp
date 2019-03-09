#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		map<string,string> s;
		s[s2]=s1;
		cin>>s1>>s2;
		s[s2]=s1;
		cin>>s1>>s2;
		s[s2]=s1;
		int N;
		cin>>N;   
		while(N--)
		{
			cin>>s1;
			if(!s.count(s1)) cout<<"Fake"<<endl;
			else cout<<s[s1]<<endl;
		}
	}
	return 0;
}

