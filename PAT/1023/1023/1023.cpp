#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	int num1[10],num2[10];
	while(cin>>s)
	{
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		unsigned int i;
		for(i=0;i<s.size();i++) num1[s[i]-'0']++;
		reverse(s.begin(),s.end()); 
		string s2;
		int f=0;
		for(i=0;i<s.length();i++)
		{
			int temp=s[i]-'0';
			temp=temp*2+f;
			s2+='0'+temp%10;
			if(temp>9) f=1;
			else f=0;
		}
		if(f==1) s2+='1';
		bool flag=true;
		for(i=0;i<s2.length();i++) num2[s2[i]-'0']++;
		for(i=0;i<=9;i++)
		{
			if(num1[i]!=num2[i])
			{
				flag=false;
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		reverse(s2.begin(),s2.end());
		cout<<s2<<endl;
	}
	return 0;
}
