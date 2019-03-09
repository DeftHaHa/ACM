#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	string s1,s2;
	bool a[100005];
	memset(a,true,sizeof(a));
	getline(cin,s1);
	getline(cin,s2);
	for(unsigned int i=0;i<s2.length();i++) a[(int)s2[i]]=false;
	for(unsigned int i=0;i<s1.length();i++)
	{
		if(a[(int)s1[i]]) printf("%c",s1[i]);
	}
	cout<<endl;
	return 0;
}