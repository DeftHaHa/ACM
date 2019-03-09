#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> path[1005];
int a[1005];
int N;
bool Max,Min;
int cnt,tp[1005];
void dfs(int p,int deep){
	if(p>N) return;
	tp[deep] = a[p];
	if((p<<1) > N && (p<<1|1) > N){
		for(int i = 0;i <= deep;i++) path[cnt].push_back(tp[i]);
		cnt++;
		return;
	}
	dfs(p<<1|1,deep+1);
	dfs(p<<1,deep+1);
}
int main()
{
	scanf("%d",&N);
	for(int i = 1;i <= N;i++) scanf("%d",&a[i]);
	cnt = 0;
	dfs(1,0);
	Max = Min = true;
	for(int i = 0 ; i < cnt;i++)
	{
		printf("%d",path[i][0]);
		for(int j = 1 ; j < path[i].size();j++){
			printf(" %d",path[i][j]);
			if(path[i][j] < path[i][j-1]) Min = false;
			else if(path[i][j] > path[i][j-1]) Max = false;
		}
		printf("\n");
	}
	if(Max) printf("Max Heap\n");
	else if(Min) printf("Min Heap\n");
	else printf("Not Heap\n");
	return 0;
}
