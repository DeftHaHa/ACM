#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int ans[105][105];
	int x=0;
	memset(ans,0,sizeof(ans));
	for(int k=1;k<=n;k++)
	{
		int i=1,j=k;
		while(i<=k&&j>=1)
		{
			ans[i][j]=++x;
			i++;
			j--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ans[j][i]) printf("%d ",ans[j][i]);
		}
		cout<<endl;
	}
	return 0;
}