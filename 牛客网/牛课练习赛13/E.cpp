#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string s;
	int n;
	while(cin>>s>>n)
	{
		int cf=0,ct=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='F') cf++;
			else ct++;
		}
		
	}
	return 0;
}
