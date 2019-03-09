#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool vis[10000005];
int main()
{
	int a,b;
	memset(vis,false,sizeof(vis));
	cin>>a>>b;
	vis[0]=true;
	for(int i=0;i<=10000000;i++)
	{
		if(vis[i])
		{
			vis[i+a]=true;
			vis[i+b]=true;
		}
	}
	for(int i=1000000;i>=0;i--)
	{
		if(!vis[i])
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}

///另一种解法  ans=a*b-a-b 
