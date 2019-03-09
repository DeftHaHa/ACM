#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string n1,n2,n3,n4;
	int ans1,ans2,ans3;
	string day[8]={" ","MON","TUE","WED","THU","FRI","SAT","SUN"};
	cin>>n1>>n2>>n3>>n4;
	int p=0;
	for(int i=0;i<min(n1.length(),n2.length());i++)
	{
		if(n1[i]==n2[i]&&n1[i]>='A'&&n1[i]<='G')
		{
			ans1=n1[i]-'A'+1;
			p=i;
			break;
		}
	}
	for(int i=p+1;i<min(n1.length(),n2.length());i++)
	{
		if(n1[i]==n2[i]&&((n1[i]>='A'&&n1[i]<='N')||(n1[i]>='0'&&n1[i]<='9')))
		{
			if(n1[i]>='A'&&n1[i]<='Z')
				ans2=n1[i]-'A'+10;
			else ans2=n1[i]-'0';
			break;
		}
	}
	for(int i=0;i<min(n3.length(),n4.length());i++)
	{
		if(n3[i]==n4[i]&&((n3[i]>='A'&&n4[i]<='Z')||(n3[i]>='a'&&n4[i]<='z')))
		{
			ans3=i;
			break;
		}
	}
	cout<<day[ans1];
	printf(" %02d:%02d\n",ans2,ans3);
	return 0;
}