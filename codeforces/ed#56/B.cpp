#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	string s;
	while(T--)
	{
		cin>>s;
		int len = s.length();
		bool flag = true;
		for(int i = 0,j = len-1;i < j;i++,j--)
		{
			if(s[i]!=s[j])
			{
				flag = false;
				break;
			}
		}
		bool ans = false;
		if(flag)
		{
			for(int i = 1;i <= len/2;i++)
			{
				if(s[i]!=s[i-1])
				{
					swap(s[i],s[i-1]);
					ans = true;
					break;
				}
			}
		}
		if(ans||!flag) cout<<s<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
