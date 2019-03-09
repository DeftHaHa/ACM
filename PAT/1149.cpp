#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
vector<int> conf[100005];
bool vis[100005];
int x[1005];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	int a,b;
	while(N--)
	{
		scanf("%d%d",&a,&b);
		conf[a].push_back(b);
		conf[b].push_back(a);
	}
	while(M--)
	{	
		int k;
		bool flag = true;
		scanf("%d",&k);
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < k;i++) {
			scanf("%d",&x[i]);
			vis[x[i]] = true;
		}
		for(int i = 0; i < k && flag;i++){
			int len = conf[x[i]].size();
			for(int j = 0;j < len;j++){
				if(vis[conf[x[i]][j]]){
					flag=false;
					break;
				}
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
