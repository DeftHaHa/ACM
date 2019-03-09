#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int na[20005],sum[20005];
bool pal(int tag)
{
	for(int i=0,j=tag;i<=j;i++,j--)
	{
		if(na[i]!=na[j]) return false;
	}
	return true;
}
int pos=0;
void add(int len)
{
	for(int i=0;i<len;i++) cout<<na[i];
	cout<<" + ";
	for(int i=len-1;i>=0;i--) cout<<na[i];
	cout<<" = ";
	memset(sum,0,sizeof(sum));
	for(int i=0;i<len;i++)
	{
		sum[i]+=na[i]+na[len-i-1];
		if(sum[i]>9)
		{
			sum[i]-=10;
			sum[i+1]++;
		}
	}
	int tag=0;
	for(int i=len+1;i>=0;i--)
	{
		if(sum[i]!=0) 
		{
			tag=i;
			break;
		}
	}
	memset(na,0,sizeof(na));
	for(int i=0;i<=tag;i++)
	{
		na[i]=sum[tag-i];
		cout<<na[i];
	}
	cout<<endl; 
	pos=tag;
}
int main()
{
	string s;
	memset(na,0,sizeof(na));
	cin>>s;
	int lens=s.length();
	for(int i=0;i<lens;i++) na[i]=s[i]-'0';
	int flag=false;
	pos=lens-1;
	for(int i=0;i<10;i++)
	{
		if(pal(pos))
		{
			for(int i=0;i<=pos;i++) cout<<na[i];
			cout<<" is a palindromic number."<<endl;
			flag=true;
			break;
		}
		add(pos+1);
		
	}
	if(!flag) cout<<"Not found in 10 iterations."<<endl;
	system("pause");
	return 0;
}