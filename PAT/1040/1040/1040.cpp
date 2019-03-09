#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int maxl=0,L=s.length();
	if(L==1) {cout<<1<<endl;return 0;}
	for(int i=0;;i++)
	{
		int left=i,right=i+1,nowl=0;
		if(s[left-maxl/2]==s[right+maxl/2])
		{
			for(;left>=0&&right<L;left--,right++)
			{
				if(s[left]!=s[right]) break;
				nowl++;
			}
			maxl=max(maxl,nowl*2);
		}
		if(i+maxl/2>=L-1) break;
	}
	if(maxl==0) maxl=1;
	for(int i=maxl/2-1;;i++)
	{
		int left=i-1,right=i+1,nowl=0;
		if(s[left-maxl/2]==s[right+maxl/2])
		{
			for(;left>=0&&right<L;left--,right++)
			{
				if(s[left]!=s[right]) break;
				nowl++;
			}
			maxl=max(maxl,nowl*2+1);
		}
		if(i+maxl/2>=L-1) break;
	}
	cout<<maxl<<endl;
	return 0;
}