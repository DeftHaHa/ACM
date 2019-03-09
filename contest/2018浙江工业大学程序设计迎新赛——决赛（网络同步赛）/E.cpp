#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n,m;
int a[1005][1005];
bool vis[1005][1005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i = 1;i <= n; i++)
			for(int j = 1;j <= m;j++)
				scanf("%d",&a[i][j]);
		
	}
	return 0;
}
