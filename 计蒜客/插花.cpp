#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char x[60005];
int main()
{
	int n;
	cin>>n;
	char ch=getchar();
	scanf("%s",x);
	int tag[40000];
	int id=0;
	for(int i=0;i<2*n;i++)
	{
		if(x[i]=='1') tag[++id]=i+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=tag[i]-i;
	}
	cout<<ans<<endl;
	return 0;
}
