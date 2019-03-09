#include<cstring>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string x;
	cin>>x;
	char s[20005];
	int sl=1;
	s[0]='&';
	s[1]='#';
	for(int i=0;i<x.length();i++)
	{
		s[++sl]=x[i];
		s[++sl]='#';
	}
	s[++sl]='*';
	int pos=0,maxr=-1;
	int p[20005];
	int ans=0;
	for(int i=1;i<sl;i++)
	{
		if(i>maxr) p[i]=1;
		else p[i]=min(p[2*pos-i],maxr-i+1);
		while(s[i+p[i]]==s[i-p[i]]) p[i]++;
		if(i+p[i]-1>maxr)
		{
			pos=i;
			maxr=i+p[i]-1;
		}
		ans=max(ans,p[i]-1);
	}
	cout<<ans<<endl;
	return 0;
}
