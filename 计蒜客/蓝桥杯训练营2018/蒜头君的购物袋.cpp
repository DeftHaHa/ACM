#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool vis[20005];
int main()
{
	int V,n;
	cin>>V>>n;
	memset(vis,false,sizeof(vis));
	int v;
	vis[0] = true;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&v);
		for(int j = V-v; j >= 0;j--)
		{
			if(vis[j]) vis[j+v] = true;
		}
	}
	for(int i = V;i >= 0 ;i--)
	{
		if(vis[i])
		{
			printf("%d\n",V-i);
			break;
		}
	}
	return 0;
}
