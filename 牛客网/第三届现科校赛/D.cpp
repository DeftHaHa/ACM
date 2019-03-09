#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int len = s.length();
		int pos = 0,now = 0;
		int ans = 0;
		for(int i = 0;i < len;i++)
		{
			if(s[i]=='W') now++;
			else now--;
			if(now<0)
			{
				now = 0;
				pos = i+1;
			}
			if(now>=0) ans = max(ans,i-pos+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
