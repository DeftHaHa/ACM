#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<int> ans[26*26*26*10+10];
int getid(char s[])
{
	return (s[0]-'A')*6760+(s[1]-'A')*260+(s[2]-'A')*10+(s[3]-'0');
}
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int id=0;
	char s[5],q[5];
	int index,ni;
	while(K--)
	{
		scanf("%d%d",&index,&ni);
		while(ni--)
		{
			scanf("%s",s);
			ans[getid(s)].push_back(index);
		}
	}
	while(N--)
	{
		scanf("%s",q);
		int tag=getid(q);
		sort(ans[tag].begin(),ans[tag].end());
		int l=ans[tag].size();
		printf("%s %d",q,l);
		for(int i=0;i<l;i++) printf(" %d",ans[tag][i]);
		printf("\n");
	}
	return 0;
}