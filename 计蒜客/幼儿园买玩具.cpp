#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k;
int a[20];
int main()
{
	memset(a,0,sizeof(a));
	cin>>n>>m>>k;
	int tot;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>tot;
		while(tot--)
		{
			cin>>x;
			a[x]++;	
		}
	}
}


