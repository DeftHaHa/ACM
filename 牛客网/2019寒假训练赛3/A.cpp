#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool vis[200005];
int main()
{
	int N,id;
	scanf("%d",&N);
	int t = N-1;
	while(t--){
		scanf("%d",&id);
		vis[id] = true;
	}
	for(int i = 1;i <= N;i++) {
		if(!vis[i]){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
