#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	int len1 = s1.length(),len2 = s2.length();
	int ans = 0;
	for(int i = 0;i < len1-len2+1;i++)
	{
		int len = 0;
		for(int j = 0;j < len2;j++)
		{
			if(s1[i+j]==s2[j]) len++;
			else break;
		}
		if(len == len2) ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}
