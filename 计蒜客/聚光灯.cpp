#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool maze[1005][1005];
int main()
{
	int sumi[1005],sumj[1005];
	memset(sumi,0,sizeof(sumi));
	memset(sumj,0,sizeof(sumj));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&maze[i][j]);
			if(maze[i][j])
			{
				sumi[i]++;
				sumj[j]++;
			}
		}
			
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(sumi[i])
		{
			int maxi=-1,mini=-1;
			for(int j=0;j<m;j++)
			{
				if(maze[i][j])
				{
					mini=j;
					break;
				}
			}
			for(int j=m-1;j>=0;j--)
			{
				if(maze[i][j])
				{
					maxi=j;
					break;
				}
			}
			if(mini!=-1)
			{
				ans+=m-mini-2*sumi[i]+maxi+1;
			}
		}
	}
	for(int j=0;j<m;j++)
	{
		if(sumj[j])
		{
			int maxi=-1,mini=-1;
			for(int i=0;i<n;i++)
			{
				if(maze[i][j])
				{
					mini=i;
					break;
				}
			}
			for(int i=n-1;i>=0;i--)
			{
				if(maze[i][j])
				{
					maxi=i;
					break;
				}
			}
			if(mini!=-1)
			{
				ans+=n-mini-2*sumj[j]+maxi+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
