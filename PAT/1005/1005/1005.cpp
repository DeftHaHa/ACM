#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string s;
	string p[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	while(cin>>s)
	{
		int sum=0;
		for(int i=0;i<s.length();i++)
		{
			sum+=s[i]-'0';
		}
		int a[10],ans[10];
		int tot=0;
		if(sum==0)
		{
			tot=1;
			a[0]=0;
		}
		while(sum>0)
		{
			a[tot++]=sum%10;
			sum/=10;
		}
		for(int i=0;i<tot;i++)
			ans[i]=a[tot-i-1];
		cout<<p[ans[0]];
		for(int i=1;i<tot;i++)
			cout<<' '<<p[ans[i]];
		cout<<endl;

	}
	return 0;
}