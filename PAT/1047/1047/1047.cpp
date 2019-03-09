#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
using namespace std;
char s[40005][5];
bool cmp(const int &a,const int &b)
{
	return strcmp(s[a],s[b])<0;
}
int main()
{
	int N,K;
	vector<int> cur[2505];
	cin>>N>>K;
	int n,t;
	for(int i=1;i<=N;i++)
	{
		scanf("%s %d",&s[i],&n);
		while(n--)
		{
			scanf("%d",&t);
			cur[t].push_back(i);
		}
	}
	for(int i=1;i<=K;i++)
	{
		int l=cur[i].size();
		printf("%d %d\n",i,l);
		sort(cur[i].begin(),cur[i].end(),cmp);
		for(int j=0;j<l;j++)
		{
			printf("%s\n",s[cur[i][j]]);
		}
	}
	return 0;
}