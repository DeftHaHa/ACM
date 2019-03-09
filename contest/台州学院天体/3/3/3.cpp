#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	bool list[1005];
	string s1,s2;
	while(getline(cin,s1))
	{
		memset(list,false,sizeof(list));
		getline(cin,s2);
		for(int i=0;i<s2.length();i++) if(s2[i]!=' ') list[(int)s2[i]]=true;
		for(int i=0;i<s1.length();i++) if(!list[(int)s1[i]]) printf("%c",s1[i]);
	}
	return 0;
}