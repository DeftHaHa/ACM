#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	int T;
	cin>>T;
	int n,s[1005];
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",&s[i]);
		sort(s,s+n,cmp);
		int ans1=0,ans2=0;
		for(int i=0;i<n;i++)
		{
			if(i&1) ans2+=s[i];
			else ans1+=s[i];
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}