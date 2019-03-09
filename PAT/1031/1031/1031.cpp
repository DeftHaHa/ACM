#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int N=s.length();
		int maxn1=0;
		for(int i=3;i<=N;i++)
		{
			maxn1=max(maxn1,min(i,(N+2-i)/2));
		}
		int n1=maxn1-1;
		int n2=N-2*(n1+1);
		int i,j;
		for(i=0,j=N-1;i<n1;i++,j--)
		{
			cout<<s[i];
			int t=n2;
			while(t--) {cout<<' ';}
			cout<<s[j]<<endl;
		}
		for(;i<=j;i++)
			cout<<s[i];
		cout<<endl;
	}
	return 0;
}
