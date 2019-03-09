#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
struct edge{
	int u,v;
}e[10005];
int col[10005];
set<int> Set;
map<int,bool> Map;
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i = 0;i < M;i++){
		scanf("%d%d",&e[i].u,&e[i].v);
	}
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int cnt = 0;
		for(int i = 0;i < N;i++) 
		{
			scanf("%d",&col[i]);
			if(!Map[col[i]]){
				Map[col[i]]=true;
				cnt++;
			}
		}
		Map.clear();
		bool flag = true;
		for(int i = 0;i < M;i++)
		{
			if(col[e[i].u]==col[e[i].v]){
				flag = false;
				break;
			}
		}
		if(flag) printf("%d-coloring\n",cnt);
		else printf("No\n");
	}
	
	return 0;
}
