#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		int len = s.length();
		bool flag1 = true,flag2 = true;
		if(s[0] == s[len-1] || s[1] == s[0]) flag1 = flag2 = false;
		if(s[0] == s[len-2] || s[1] == s[len-1]) flag1 = false;
		for(int i = 2;i < len;i++)
		{
			if(s[i]==s[i-1])
			{
				flag1 = flag2 = false;
			}
			if(s[i]==s[i-2]) flag1 = false;
		}
		if(flag1) printf("coolest\n");
		else if(flag2) printf("cooler\n");
		else printf("cool\n");
	}
	return 0;
}
