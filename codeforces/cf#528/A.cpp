#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len  = s.length();
	int i = len/2-1,j = len/2;
	int cnt = 0;
	if(len&1){
		cout<<s[len/2];
		j++;
		cnt = 1;
	}
	for(;cnt < len;)
	{
		if(cnt&1){
			cout<<s[j];
			j++;
		}
		else{
			cout<<s[i];
			i--;
		}
		cnt++;
	}
	cout<<endl;
	return 0;
}
