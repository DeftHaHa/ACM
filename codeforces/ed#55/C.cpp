#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[100005];
int sum[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	
	int n,m;
	cin>>n>>m;
	int s,r;
	for(int i = 0;i < n; i++)
	{
		scanf("%d%d",&s,&r);
		v[s].push_back(r); 
	}
	int ans = 0;
	memset(sum,0,sizeof(sum));
	for(int i = 1;i <= m;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		for(int j = 0;j < v[i].size();j++)
		{
			if(j>0)v[i][j] += v[i][j-1];
			if(v[i][j]>=0) sum[j] += v[i][j];
			ans = max(ans,sum[j]);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
