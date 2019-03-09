#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int ans = 0;
	bool flag = false;
	for(int i = s.length() - 1;i>=0;i--)
	{
		if(s[i]==' '&&flag) break;
		else if(s[i]!=' ') flag = true;
		if(flag) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
